# containers

This project is meant to mimic std::set, std::vector, std::map and iterators, all that using templates.

As this is kind of a library, it needs some tester or main in order to work.

You can run :  
$> make  
to launch the program with default main file.

Both my stl implementation and original stl will be compiled. As a result, there will be 2 executables. ft_containers is mine, stl_containers the original.

Now if you want to test with your own main, just replace the original by yours in the Makefile, in the SRCS field
