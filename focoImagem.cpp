#include <opencv2/imgcodecs.hpp>  
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){
	
	string path = "/home/joao/Área de Trabalho/img/parede.jpg";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode; //declara o nome das imagens
	cout << img.size() <<endl;
	
	cvtColor(img,imgGray, COLOR_BGR2GRAY); //deixa a imagem cinza
	GaussianBlur(img, imgBlur, Size(3, 3),3,0); //borra a imagem quanto maior o numero mais borra
	Canny(imgBlur, imgCanny, 75, 150); //identifica bordas nas imagens, usa uma imagem borrada
	
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));//cria um nucleo, define a espessura das linhas de contorno maior os numeros maior aespessura da linha. numeros pecisão ser iguais.
	dilate(imgCanny, imgDil, kernel); //dilata as linhas da borda.
	erode(imgDil, imgErode, kernel); //refina as linhas dilatadas
	
	imshow("Imagem",img);
	imshow("Imagem Gray", imgGray);
	imshow("Imagem Blur", imgBlur);
	imshow("Imagem Canny",imgCanny);
	imshow("Imagem Dilation", imgDil);
	imshow("Imagem Erode",imgErode);
	waitKey(0);
	
	return 0;
	}
