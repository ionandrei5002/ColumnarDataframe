#include <column.h>

Column::Column() {}
Column::~Column() {}
uint64_t Column::size()
{
    return this->_size;
}

template<typename T>
TypedColumn<T>::TypedColumn() {}
template<typename T>
TypedColumn<T>::~TypedColumn() {}

template<typename T>
void TypedColumn<T>::append(const ByteBuffer& value) 
{
    _type temp;
    temp = *reinterpret_cast<_type*>(value._data);
    _store.push_back(temp);
    this->_size++;
}

template<>
void TypedColumn<StringType>::append(const ByteBuffer& value) 
{
    _store.push_back(value);
    this->_size++;
}

template<typename T>
const ViewByteBuffer TypedColumn<T>::read(uint64_t position) const
{
    const _type* temp;
    temp = &_store.at(position);

    ViewByteBuffer value(reinterpret_cast<const char*>(temp), sizeof(_type));

    return value;
}

template<>
const ViewByteBuffer TypedColumn<StringType>::read(uint64_t position) const
{
    return ViewByteBuffer(_store.at(position));
}

template class TypedColumn<UInt8Type>;
template class TypedColumn<UInt16Type>;
template class TypedColumn<UInt32Type>;
template class TypedColumn<UInt64Type>;
template class TypedColumn<Int8Type>;
template class TypedColumn<Int16Type>;
template class TypedColumn<Int32Type>;
template class TypedColumn<Int64Type>;
template class TypedColumn<FloatType>;
template class TypedColumn<DoubleType>;
template class TypedColumn<StringType>;