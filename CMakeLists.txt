cmake_minimum_required(VERSION 3.12...3.28)

project(ModernCpp LANGUAGES CXX)

# 设置 C++20 标准（向下兼容 C++11/14/17）
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 防止在源码根目录下就地构建
if( STREQUAL )
    message(FATAL_ERROR "In-source builds not allowed. Please build in a separate build directory!")
endif()

# 基础线程库依赖
find_package(Threads REQUIRED)

# 统一编译选项
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|AppleClang|GNU")
    add_compile_options(
        -Wall
        -Wextra
        -Wno-unused-variable
        -Wno-unused-parameter
    )
endif()

# 所有可正常独立编译运行的完整示例（排除故意演示编译错误的反例与不含 main 的代码片段）
set(BUILDABLE_SOURCES
    "src/1-1.cpp"
    "src/2-1.cpp"
    "src/2-2.cpp"
    "src/2-3.cpp"
    "src/3-1.cpp"
    "src/4-1.cpp"
    "src/5-1.cpp"
    "src/5-2.cpp"
    "src/6-1.cpp"
    "src/6-2.cpp"
    "src/6-3.cpp"
    "src/6-4.cpp"
    "src/6-5.cpp"
    "src/6-7.cpp"
    "src/6-8.cpp"
    "src/6-9.cpp"
    "src/7-1.cpp"
    "src/7-3.cpp"
    "src/7-5.cpp"
    "src/7-6.cpp"
    "src/7-7.cpp"
    "src/7-8.cpp"
    "src/7-9.cpp"
    "src/7-10.cpp"
    "src/7-11.cpp"
    "src/9-1.cpp"
    "src/9-2.cpp"
    "src/9-3.cpp"
    "src/9-4.cpp"
    "src/10-6.cpp"
    "src/11-1.cpp"
    "src/11-2.cpp"
    "src/11-3.cpp"
    "src/11-4.cpp"
    "src/11-5.cpp"
    "src/12-8.cpp"
    "src/12-9.cpp"
    "src/12-10.cpp"
    "src/12-11.cpp"
    "src/13-2.cpp"
    "src/13-7.cpp"
    "src/14-2.cpp"
    "src/14-4.cpp"
    "src/14-9.cpp"
    "src/14-12.cpp"
    "src/15-1.cpp"
    "src/15-2.cpp"
    "src/15-3.cpp"
    "src/15-4.cpp"
    "src/15-6.cpp"
    "src/17-1.cpp"
    "src/17-3.cpp"
    "src/18-1.cpp"
    "src/18-2.cpp"
    "src/18-3.cpp"
    "src/18-4.cpp"
    "src/18-5.cpp"
    "src/18-6.cpp"
    "src/20-1.cpp"
    "src/20-2.cpp"
    "src/20-3.cpp"
    "src/20-4.cpp"
    "src/20-5.cpp"
    "src/20-6.cpp"
    "src/20-9.cpp"
    "src/20-10.cpp"
    "src/20-11.cpp"
    "src/21-1.cpp"
    "src/21-3.cpp"
    "src/21-4.cpp"
    "src/21-5.cpp"
    "src/21-8.cpp"
    "src/22-1.cpp"
    "src/22-2.cpp"
    "src/23-1.cpp"
    "src/24-4.cpp"
    "src/25-1.cpp"
    "src/25-3.cpp"
    "src/26-1.cpp"
    "src/27-3.cpp"
    "src/27-7.cpp"
    "src/27-10.cpp"
    "src/27-12.cpp"
    "src/27-14.cpp"
    "src/27-15.cpp"
    "src/27-17.cpp"
    "src/29-1.cpp"
    "src/29-2.cpp"
    "src/29-3.cpp"
    "src/29-4.cpp"
    "src/30-1.cpp"
    "src/30-4.cpp"
    "src/31-1.cpp"
    "src/31-2.cpp"
    "src/31-3.cpp"
    "src/31-4.cpp"
    "src/31-5.cpp"
    "src/31-6.cpp"
    "src/31-7.cpp"
    "src/31-8.cpp"
    "src/31-9.cpp"
    "src/31-10.cpp"
    "src/31-12.cpp"
    "src/34-1.cpp"
    "src/34-2.cpp"
    "src/34-5.cpp"
    "src/34-6.cpp"
    "src/34-7.cpp"
    "src/34-8.cpp"
    "src/34-9.cpp"
    "src/34-11.cpp"
    "src/35-1.cpp"
    "src/35-2.cpp"
    "src/35-3.cpp"
    "src/35-4.cpp"
    "src/35-5.cpp"
    "src/35-6.cpp"
    "src/35-7.cpp"
    "src/35-8.cpp"
    "src/35-10.cpp"
    "src/35-11.cpp"
    "src/35-12.cpp"
    "src/35-13.cpp"
    "src/35-15.cpp"
    "src/35-17.cpp"
    "src/35-18.cpp"
    "src/35-19.cpp"
    "src/36-1.cpp"
    "src/36-2.cpp"
    "src/36-3.cpp"
    "src/37-1.cpp"
    "src/37-2.cpp"
    "src/37-3.cpp"
    "src/37-4.cpp"
    "src/37-5.cpp"
    "src/37-6.cpp"
    "src/37-7.cpp"
    "src/37-8.cpp"
    "src/37-11.cpp"
    "src/37-12.cpp"
    "src/38-1.cpp"
    "src/38-2.cpp"
    "src/38-3.cpp"
    "src/38-5.cpp"
    "src/38-6.cpp"
    "src/40-1.cpp"
    "src/40-2.cpp"
    "src/40-6.cpp"
    "src/40-7.cpp"
    "src/40-8.cpp"
    "src/41-15.cpp"
    "src/41-16.cpp"
    "src/41-17.cpp"
    "src/42-3.cpp"
    "src/42-4.cpp"
    "src/42-5.cpp"
    "src/42-6.cpp"
)

# 为每个示例生成独立可执行目标，格式如 ex01_01, ex20_02
foreach(source_file ${BUILDABLE_SOURCES})
    get_filename_component(file_stem ${source_file} NAME_WE)
    string(REPLACE "-" ";" parts ${file_stem})
    list(GET parts 0 chapter)
    list(GET parts 1 index)
    
    # 补齐两位数前缀，便于按章节顺序构建和筛选
    string(LENGTH "${chapter}" chapter_len)
    if(chapter_len EQUAL 1)
        set(chapter "0${chapter}")
    endif()
    
    string(LENGTH "${index}" index_len)
    if(index_len EQUAL 1)
        set(index "0${index}")
    endif()
    
    set(target_name "ex${chapter}_${index}")
    
    add_executable(${target_name} ${source_file})
    target_link_libraries(${target_name} PRIVATE Threads::Threads)
endforeach()

# 兼容原有的旧目标名称别名
if(TARGET ex01_01)
    add_custom_target(ex01 DEPENDS ex01_01)
endif()
if(TARGET ex02_01)
    add_custom_target(ex02-01 DEPENDS ex02_01)
endif()
if(TARGET ex02_02)
    add_custom_target(ex02-02 DEPENDS ex02_02)
endif()
if(TARGET ex03_01)
    add_custom_target(ex03 DEPENDS ex03_01)
endif()
if(TARGET ex04_01)
    add_custom_target(ex04 DEPENDS ex04_01)
endif()
