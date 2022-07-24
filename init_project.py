from asyncore import read
import os
import sys

work_space = "./"
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
    
    c_include = os.makedirs(include_path)
    c_src = os.makedirs(src_path)
    c_t_u = os.makedirs(test_path_ut)
    c_t_b = os.makedirs(test_path_benchmark)
    
    os.chdir(work_space + project_name)

    file_readme_ = os.open(readme_file, os.O_CREAT|os.O_RDWR)
    t_r_c = os.close(file_readme_)

    file_CMakeLists_ = os.open(cmake_file, os.O_CREAT|os.O_RDWR)
    t_c_c = os.close(file_CMakeLists_)
    
    print(t_c_c,t_r_c,c_t_b,c_t_u,c_src,c_include)
    
    if  (c_include and c_src and c_t_u and c_t_b):
        return True

    if  (t_r_c and t_c_c):
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
