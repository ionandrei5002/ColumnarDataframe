#ifndef COLUMN_H
#define COLUMN_H

#include <types.h>
#include <bytebuffer.h>
#include <deque>

class Column
{
protected:
    uint64_t _size = 0;
public:
    Column();
    virtual ~Column();
    virtual void append(const ByteBuffer& value) = 0;
    virtual const ViewByteBuffer read(uint64_t position) const = 0;
    uint64_t size();
};

template<typename T>
class TypedColumn: public Column
{
private:
    typedef typename T::c_type _type;
    std::deque<typename T::c_type> _store;
public:
    explicit TypedColumn();
    ~TypedColumn();
    void append(const ByteBuffer& value) override;
    const ViewByteBuffer read(uint64_t position) const override;
};

typedef TypedColumn<UInt8Type> UInt8Column;
typedef TypedColumn<UInt16Type> UInt16Column;
typedef TypedColumn<UInt32Type> UInt32Column;
typedef TypedColumn<UInt64Type> UInt64Column;
typedef TypedColumn<Int8Type> Int8Column;
typedef TypedColumn<Int16Type> Int16Column;
typedef TypedColumn<Int32Type> Int32Column;
typedef TypedColumn<Int64Type> Int64Column;
typedef TypedColumn<FloatType> FloatColumn;
typedef TypedColumn<DoubleType> DoubleColumn;
typedef TypedColumn<StringType> StringColumn;

#endif // COLUMN_H