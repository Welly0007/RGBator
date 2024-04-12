#include <bits/stdc++.h>
#include "Image_Class.h"
using namespace std;


//====== Black and White ======//
void Black_and_White(Image &img) {

    Image newImage(img.width, img.height); 

    // Filter
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {

            unsigned int avg = 0;
            for (int k = 0; k < img.channels; ++k) {
                avg += img(i, j, k);
            }
            avg = avg / 3;
            for (int k = 0; k < 3; ++k) {
                if (avg > 127) {
                    img(i, j, k) = 255;
                    newImage(i,j,k) = img(i,j,k);
                } else {
                    img(i, j, k) = 0;
                    newImage(i,j,k) = img(i,j,k);
                }
            }
        }
    }

    img = newImage;
}

//====== Merge Images ======//
void Merge(Image &img, Image &img2) {
    // Read Image
    Image newImage(img.width, img.height);

    for (int i = 0; i < img.width; ++i)
    {
        for (int j = 0; j < img.height; ++j)
        {
            for (int k = 0; k < img.channels; ++k)
            {
                img(i, j, k) = (img(i,j, k) + img2(i,j,k) ) / 2;
                newImage(i, j, k) = img(i, j, k);
            }
        }
    }

    img = newImage; 

}

//====== Dark & Light ======//
void Dark_and_Light(Image &image)
{
    // Read Image
    string ch;
    // Image img = Read_Img(User_img);
    Image newImage(image.width, image.height);

    cout << "1) Darker\n";
    cout << "2) Lighter\n";
    cout << "=> ";
    cin >> ch;
    // dark
    if (ch == "1")
    {
        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    newImage(i, j, k) = image(i, j, k) * 0.250;
                }
            }
        }
    }
    // light
    else if (ch == "2")
    {
        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (img(i, j, k) > image.width / 2 && img(i, j, k) > image.height / 2)
                    {
                        newImage(i, j, k) = min(image(i, j, k) + 170, 255);
                    }
                    else
                    {
                        newImage(i, j, k) = min(image(i, j, k) + 70, 255);
                    }
                }
            }
        }
    }
    else
    {
        cout << "Invalid operation";
    }

    image = newImage; // Assign the pointer to the dynamically allocated object
}

//====== Crop Image ======//
void Crop(Image &img) {
    int x, y, width, height;
    cout << "Enter starting point (x, y) of the area to keep\n";
    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;
    cout << "Enter dimensions (width x height) of the area to cut\n";
    cout << "Width: ";
    cin >> width;
    cout << "Height: ";
    cin >> height;
    // Check if cropping dimensions exceed image size
    if (x + width > img.width || y + height > img.height) {
        cout << "Error: Cropping dimensions exceed image size" << endl;
        return;
    }
    Image newImage(img.width, img.height);


    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            for (int k = 0; k < img.channels; ++k) {
                newImage(i, j, k) = img(x + i, y + j, k);
            }
        }
    }

    img = newImage; 
}

//====== Adding a Frame ======//
void Frame(Image &img) {
    Image newImage(img.width, img.height); 
    int border = img.width / 50; // Width of the frame
    int innerBorder = img.width / 100; // Width of the inner frame
    string ch;
    while (true) {
        cout << "Choose Frame 1)Blue Frame 2)Fancy";
        cin >> ch;
        cin.ignore();
        if (ch == "1") {
            for (int i = 0; i < img.width; i++) {
                for (int j = 0; j < img.height; j++) {
                    if (i < border || i >= img.width - border || j < border || j >= img.height - border) {
                        img(i, j, 0) = 0;
                        img(i, j, 1) = 0;
                        img(i, j, 2) = 255;
                    }
                }
            }
            break;
        }
        else if (ch == "2") {
            for (int i = 0; i < img.width; i++) {
                for (int j = 0; j < img.height; j++) {
                    if (i < border || i >= img.width - border || j < border || j >= img.height - border) {
                        img(i, j, 0) = 0;
                        img(i, j, 1) = 0;
                        img(i, j, 2) = 255;
                    }
                    if ((i >= 2 * border && i < img.width - 2 * border && j >= 2 * border && j < img.height - 2 * border)&& (i < border * 2 + innerBorder || i >= img.width - border * 2 - innerBorder ))                                                                                              || j < border * 2 + innerBorder || j >= img.height - border * 2 - innerBorder)) {
                        for (int k = 0; k < 3; ++k) {
                            img(i, j, k) = 255;
                        }
                    }
                }
            }
            break;
        }
    }
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            for (int k = 0; k <3 ; ++k) {
                newImage(i,j,k)=img(i,j,k);
            }
        }
    }
    img = newImage; 
}

//====== Detect Image Edges ======//
void Detect_Image(Image &img) {

Image newImage(img.width, img.height);

 for (int i = 0; i < img.width; ++i)
    {
        for (int j = 0; j < img.height; ++j)
        {
            unsigned int avg = 0;
            for (int k = 0; k < img.channels; ++k)
            {
                avg += img(i, j, k);
            }
            avg /= 3;
            for (int l = 0; l < 3; ++l) {
                img(i,j,l) = avg;
            }

        }
    }

    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {

            unsigned int avg = 0;
            for (int k = 0; k < img.channels; ++k) {
                avg += img(i, j, k);
            }
            avg = avg / 3;
            for (int k = 0; k < 3; ++k) {
                if (avg > 127) {
                    img(i, j, k) = 255;
                } else {
                    img(i, j, k) = 0;
                }
            }
        }
    }

    for(int i = 0; i < img.width; i++) {
        for(int j = 0; j < img.height; j++){
            for(int k = 0; k < img.channels; k++) {
                if(img(i,j,k) == 0 && img(i++,j,k) == 0 && img(i--,j,k) == 0 && img(i,j + 1,k) == 0 &&
                img(i,j - 1,k) == 0) {
                    newImage(i,j,k) = 255;
                } else {
                    newImage(i,j,k) = img(i,j,k);
                }
            }
        }
    }

    img = newImage;
}

//====== Resizing Image ======//
void Resize_Image(Image &img, int w, int h) {


    Image newImage(w, h);

    float sr = static_cast<float>(img.width) / w;
    float sc = static_cast<float>(img.height) / h;

    // Resize the image
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < 3; ++k) {
                newImage(i, j, k) = img(round(i * sr), round(j * sc), k);
            }
        }
    }
    img = newImage;
}

void Infrared(Image &img) {
    
    Image newImage(img.width, img.height);
    for(int i = 1; i < img.width; i++) {
        for(int j = 1; j < img.height; j++) {

            int red = img(i, j, 0);
            int green = img(i, j, 1);
            int blue = img(i, j, 2);

            red = 255;
            green = 255 - green;
            blue = 255 - blue;
            // Setting new RGB values
            img(i, j, 0) = red;
            img(i, j, 1) = green;
            img(i, j, 2) = blue;
            newImage(i,j,0) = img(i, j, 0);
            newImage(i,j,1) = img(i, j, 1);
            newImage(i,j,2) = img(i, j, 2);
        }
    }

    img = newImage; 
}


int main() {

    return 0;
}