// main.cpp : Defines the entry point for the console application.
//

#include <stdio.h>  // printf
#include <iostream>  
#include <amp.h>  
#include <WinBase.h>  

extern "C" {
	void RunExample1();
	void RunExample2();
	void RunExample3();
	void RunExample4();
	void RunExample5();
	//void GPURunExample2();
}

int main(int argc, char* argv[])
{
	// select which example to run here
	const int which = 2;

	//count time
	LARGE_INTEGER freq;
	LARGE_INTEGER strt;
	LARGE_INTEGER ed;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&strt);

	// run the appropriate example
	switch (which) {
	case 1:  RunExample1();  break;
	case 2:  RunExample2();  break;
	case 3:  RunExample3();  break;
	case 4:  RunExample4();  break;  // Note:  example4 reads output from example 3
	case 5:  RunExample5();  break;
	default:  printf("There is no example number %d\n", which);
	}

	//count time
	QueryPerformanceCounter(&ed);
	printf("CPU耗时: %d 毫秒\r\n", (ed.QuadPart - strt.QuadPart) * 1000 / freq.QuadPart);
	//QueryPerformanceCounter(&strt);
	//concurrency::array_view<float> myView(COUNT, nickName_GPU); //将数据打入显存  
	//concurrency::parallel_for_each(myView.extent, [=](concurrency::index<1> idx) restrict(amp)
	//{
	//// run the appropriate example
	//	switch (which) {
	//	case 2:  GPURunExample2();  break;
	//	default:  printf("There is no example number %d\n", which);
	//	}
	//});
	////count time
	//QueryPerformanceCounter(&ed);
	//printf("GPU耗时: %d 毫秒\r\n", (ed.QuadPart - strt.QuadPart) * 1000 / freq.QuadPart);
	//getchar();
	return 0;
}

