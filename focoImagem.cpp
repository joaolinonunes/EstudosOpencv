#include <opencv2/imgcodecs.hpp>  
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){
	
	string path = "/home/joao/Área de Trabalho/img/parede.jpg"; //o caminho onde esta a imagem
	Mat img = imread(path); //classe Mat armazena imagem matriz
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode; //declara o nome das imagens
	cout << img.size() <<endl; //mostra o tamanho da imagem
	
	cvtColor(img,imgGray, COLOR_BGR2GRAY); //deixa a imagem cinza
	GaussianBlur(img, imgBlur, Size(3, 3),3,0); //borra a imagem quanto maior o numero mais borra
	Canny(imgBlur, imgCanny, 75, 150); //identifica bordas nas imagens, usa uma imagem borrada
	
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));//cria um nucleo, define a espessura das linhas de contorno maior os numeros maior aespessura da linha. numeros pecisão ser iguais.
	dilate(imgCanny, imgDil, kernel); //dilata as linhas da borda.
	erode(imgDil, imgErode, kernel); //refina as linhas dilatadas
	
	imshow("Imagem",img); //mostra a imagem 
	imshow("Imagem Gray", imgGray); //mostra a imagem com cinza 
	imshow("Imagem Blur", imgBlur); //mostra a imagem borrada
	imshow("Imagem Canny",imgCanny); //mostra somente as bordas da imagem
	imshow("Imagem Dilation", imgDil); //mostra somente as bordas da imagem dilatadas
	imshow("Imagem Erode",imgErode); //mostra somente as bordas da imagem dilatadas refinadas
	waitKey(0);
	//TEST PULL
	return 0;
	}
