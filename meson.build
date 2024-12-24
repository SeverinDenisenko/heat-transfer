project('heat-transfer', 'cpp', 'c', default_options : ['warning_level=3', 'cpp_std=c++23'])

cmake = import('cmake')
opt_var = cmake.subproject_options()
opt_var.add_cmake_defines({'MATPLOTPP_BUILD_WITH_SANITIZERS': false})
matplotplusplus_proj = cmake.subproject('matplotplusplus', options: opt_var)
matplotplusplus_lib = matplotplusplus_proj.dependency('matplot')
nodesoup_lib = matplotplusplus_proj.dependency('nodesoup')

executable(
	'heat-transfer-solver',
	sources : ['main.cpp'],
	dependencies : [matplotplusplus_lib, nodesoup_lib]
)
