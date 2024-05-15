project(
    'boost-test',
    'cpp',
    default_options: ['warning_level=3', 'werror=true', 'cpp_std=c++20'],
    license: 'Apache-2.0',
    version: '0.1',
    meson_version: '>=1.1',
)

add_project_arguments(
    '-Wno-psabi',
    '-Wuninitialized',
    '-DBOOST_SYSTEM_NO_DEPRECATED',
    '-DBOOST_ASIO_NO_DEPRECATED',
    '-DBOOST_ERROR_CODE_HEADER_ONLY',
    '-DBOOST_NO_RTTI',
    '-DBOOST_NO_TYPEID',
    '-DBOOST_ALL_NO_LIB',
    '-DBOOST_ASIO_DISABLE_THREADS',
    '-DBOOST_ALLOW_DEPRECATED_HEADERS',
    '-DBOOST_ASIO_HAS_IO_URING',
    '-DBOOST_ASIO_DISABLE_EPOLL',
    '-DBOOST_ASIO_USE_TS_EXECUTOR_AS_DEFAULT',
    language: 'cpp',
)

boost = dependency('boost', version: '>=1.71.0', include_type: 'system')

default_deps = [
    boost,
]

srcfiles = [
    'test.cpp'
]

bindir = get_option('prefix') + '/' +get_option('bindir')

executable('boost-test',srcfiles,
            dependencies: default_deps,
            install: true,
            install_dir:bindir)
