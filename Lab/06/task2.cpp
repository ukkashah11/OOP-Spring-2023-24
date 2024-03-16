#include <iostream>
#include <cstring>
#include<cstdlib>
#include <ctime>
using namespace std;
const int width=2,height=3;
class Image{
    private:
    int width, height;
    int* img_data;
    public:
    Image(int w, int h, const int* data): width(w), height(h){
        img_data = new int[width*height];
        memcpy(img_data, data, width*height*sizeof(int));
    }
    Image(const Image &obj): width(obj.width), height(obj.height){
        img_data = new int[width*height];
        memcpy(img_data, obj.img_data,  width*height*sizeof(int));
    }
    void display(){
        cout<<"Image Specifications\n";
        cout<<"Height: "<<height<<endl;
        cout<<"Width: "<<width<<endl;
        cout<<"Image Data: \n";
        int i=1;
         for (int i = 0; i < width * height; ++i) {
            std::cout << img_data[i] << " ";
            if ((i + 1) % width == 0)cout << "\n";
        }
    }
    void updateData(){
    for(int i=0; i<width*height; i++){
        if(img_data[i]<=0){
            img_data[i] = rand() % 255 + 1;
        }
    }
}
    ~Image(){
        delete[] img_data;
    }
    
};
int main(){
   srand(static_cast<unsigned int>(time(0)));
    int data[width*height] = {0, -66, 234, 86, 93, 100};
    Image img(width, height, data);
    Image img2 = img;
    cout<<"Original Image Specifications:\n";
    img.display();
    cout<<"Copied Image Specifications:\n";
    img2.display();
    img.updateData();
    cout<<"Original Image Specifications after Update:\n";
    img.display();
    cout<<"Copied Image Specifications after Update:\n";
    img2.display();
}

