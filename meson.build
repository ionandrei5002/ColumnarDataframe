project('ColumnarDataframe', 
    'cpp',
    version : '0.1.0',
    license : 'MIT',
    default_options : [
        'cpp_std=c++2a',
        'cpp_args=[
            "-std=c++2a",
            "-fconcepts",
            "-flto",        
            "-march=native",
            "-m64",
            "-Werror",
            "-Wno-unused-parameter",
            "-Wfatal-errors",
            "-pedantic-errors",
            "-Wall",
            "-Wno-missing-braces",
            "-Wcast-align",
            "-Wcast-qual",
            "-Wctor-dtor-privacy",
            "-Wextra",
            "-Wformat=2",
            "-Wmissing-declarations",
            "-Wno-long-long",
            "-Wnon-virtual-dtor",
            "-Woverlength-strings",
            "-Woverloaded-virtual",
            "-Wredundant-decls",
            "-Wreorder",
            "-Wswitch-default",
            "-Wunused-variable",
            "-Wwrite-strings",
            "-Wno-variadic-macros",
            "-Wno-unused-local-typedef",
            "-Wno-language-extension-token",
            "-fstrict-aliasing",
            "-Wconversion",
            "-Wfloat-equal",
            "-Wold-style-cast",
            "-Wunreachable-code",
            "-Wshadow",
            "-Wpointer-arith",
            "-Wcast-align",
            "-Wformat-nonliteral",
            "-Winit-self",
            "-floop-parallelize-all",
            "-ftree-parallelize-loops=4"
        ]'  
    ]
)

catch2 = dependency('catch2', version : '2.4.0')

inc = include_directories('include')

subdir('include')
subdir('source')
subdir('tests')

executable(
    'ColumnarDataframe', 
    ['main.cpp'],
    include_directories: inc,
    link_with: libcolumnardataframe,
    install: true
)