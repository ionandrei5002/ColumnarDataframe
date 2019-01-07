project('ColumnarDataframe', 
    'cpp',
    version : '0.1.0',
    license : 'MIT',
    default_options : ['cpp_std=c++17']
    )

catch2 = dependency('catch2', version : '2.4.0')

inc = include_directories('include')

subdir('include')
subdir('source')
subdir('tests')

executable('ColumnarDataframe', 
    ['main.cpp']
)