**Command to run OpenMP codes:**                
g++ filename.cpp -lgomp -o filename.cpp         
./filename    

**For CUDA Practicals you need to download the raw files** to see the complete include statements as they are not supported by ipynb in Github

**If CUDA is not present in colab:**               
!nvcc --version              
!pip install git+https://github.com/afnan47/cuda.git         
%load_ext nvcc_plugin      
