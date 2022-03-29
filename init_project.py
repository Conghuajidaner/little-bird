import os
import sys

work_space = "/root/Code/dev/little-bird/"
project_name = ""

def format_print(info, flag):
    if flag == True:
        info += " :)"
    else:
        info += " :("
    info_len = len(info) + 2

    for idx in range(info_len):
        print("=", end='')
    print("\n", info)
    for idx in range(info_len):
        print("=", end='')
    print("\n")

def is_lagel(project_name):
    pass

def is_project(project_name):
    current_path = os.getcwd()
    current_list = os.listdir(current_path)

    for element in current_list:
        if element == project_name:
            return True
    return False

def create_project(project_name):
    include_path = work_space +  project_name + "/include"
    src_path = work_space +  project_name + "/src"

    test_path_ut = work_space +  project_name + "/test/utest"
    test_path_benchmark = work_space +  project_name + "/test/benchmark"

    readme_file = "README.md"
    cmake_file = "CMakeLists.txt"

    cmd_mkdir_director_include = "mkdir -p " +  include_path
    cmd_mkdir_director_src = "mkdir -p " + src_path
    cmd_mkdir_director_test_tu = "mkdir -p " + test_path_ut
    cmd_mkdir_director_test_benchmark = "mkdir -p " + test_path_benchmark

    cmd_touch_file_readme = "touch " + readme_file
    cmd_touch_file_cmake = "touch " + cmake_file
    
    os.system(cmd_mkdir_director_include)
    os.system(cmd_mkdir_director_src)
    os.system(cmd_mkdir_director_test_tu)
    os.system(cmd_mkdir_director_test_benchmark)
    
    os.chdir(work_space + project_name)

    os.system(cmd_touch_file_readme)
    # os.system("echo # " + str.upper(project_name) + ">" )
    os.system(cmd_touch_file_cmake)

    if os.path.exists(include_path) and os.path.exists(src_path) and os.path.exists(readme_file) and os.path.exists(cmake_file):
            return True

    return False

if __name__ == '__main__':
    # workspace
    if len(sys.argv) != 2:
        format_print("Please check params number", False)
        exit(1)
    project_name = sys.argv[1]
    ret = os.path.exists(work_space)

    if ret == True:
        is_project_ret = is_project(project_name)

        if is_project_ret == False:
            ret = create_project(project_name)
 
            if ret == True:
                format_print("PROJECT INIT SUCCESSFUL", True)
            else:
                format_print("PROJECT INIT FAIL", False)
        else:
            format_print("PROJECT ALREDY EXISTS", False)
    else:
        format_print("Please check workspace directoy", False)
