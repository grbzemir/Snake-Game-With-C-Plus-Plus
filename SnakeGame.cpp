#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

bool gameOver;

const int width = 20; // ekran genişliği
const int height = 20; // ekran yüksekliği
int x , y , FruitX , FruitY , score ; // yılanın başlangıç konumu
int uzunlukX[100] ; // yılanın uzunluğu
int uzunlukY[100];  // yılanın uzunluğu
int nTail; // yılanın uzunluğu

enum eDirecton { STOP = 0 , LEFT , RIGHT , UP , DOWN }; // yılanın hareket yönleri
eDirecton yon; // yılanın hareket yönleri

// fruit yem olarak düşünülebilir

void Setup()

{

    gameOver = false;
    yon = STOP;
    x = width / 2; // ekran genişliği / 2 
    y = height / 2; // ekran yüksekligi / 2

    FruitX = rand() % width; // rastgele yem konumu
    FruitY = rand() % height; // rastgele yem konumu

    score = 0;

}

void Draw()

{

    system("cls"); // ekranı temizler

    for ( int i = 0; i < width+2; i++)

        cout<<"#";
        cout<<endl;
        
    

    for (int  i = 0; i < height; i++)
     
     {
	 
    
        for( int j = 0; j < width ; j++)

        {
		

            if(j==0)
            
                cout<<"#";

            if( i  == y && j == x)
                
                cout<<"O";
            
            else if ( i == FruitY && j == FruitX)
                
                cout<<"F";

            else   

            {

                bool print = false; // yılanın uzunluğu için gerekli olan değişken
                for(int k = 0; k < nTail ; k++)

                {
                    
                    if(uzunlukX[k] == j && uzunlukY[k] == i)
                    
                    {
                        cout<<"O";
                        print = true; // yazdirma yaptık
                    
                    }

                    
                }

                if(!print)
                cout<<" ";

            }
                
                
            
           
    

           if (j==width - 1)

           

               cout<<"#";

           
       }
       cout<<endl;
       
   }
   
   for(int i = 0; i < width+2 ; i++)
   
   cout<<"#";
   cout<<endl;
   cout<<"Score:"<<score<<endl;
           
    
}

void Giris()

{

    if(_kbhit()) // klavyeden bir tuşa basıldığında

    {

        switch(_getch()) // klavyeden basılan tuşun değerini alır

        {

            case 'a':

                yon = LEFT;

                break;

            case 'd':

                yon = RIGHT;

                break;

            case 'w':

                yon = UP;

                break;

            case 's':

                yon = DOWN;

                break;

            case 'x':

                gameOver = true;

                break;

        }

    }



}


void Hareket()

{
    
    int prevX = uzunlukX[0]; // yılanın başlangıç konumu perv ile aldık
    int prevY = uzunlukY[0]; // yılanın başlangıç konumu perv ile aldık
    int prev2X, prev2Y;
    uzunlukX[0] = x; // yılanın başlangıç konumu
    uzunlukY[0] = y; // yılanın başlangıç konumu

    int i;

    for(i = 1 ; i < nTail ; i++)

    {

        prev2X = uzunlukX[i];

        prev2Y = uzunlukY[i];

        uzunlukX[i] = prevX;

        uzunlukY[i] = prevY;

        prevX = prev2X;

        prevY = prev2Y;

    }

    switch (yon)

    {

        case LEFT:

            x--;

            break;

        case RIGHT:

            x++;

            break;

        case UP:

            y--;

            break;

        case DOWN:

            y++;

            break;

        default:

            break;

    }

    if(x > width || x < 0 || y > height || y < 0) // eğer yılanın başı ekranın dışına çıkarsa oyunu bitir

        gameOver = true; // eğer yılanın başı ekranın dışına çıkarsa oyunu bitir

        for(int i = 0; i < nTail ; i++)
            
                if(uzunlukX[i] == x && uzunlukY[i] == y)
                
                    gameOver = true;



    if(x == FruitX && y == FruitY) // eğer yılanın başı yeme değdiyse

    {
        
        score = score + 10; // skoru 10 arttır

        FruitX = rand() % width;  // rastgele yem konumu

        FruitY = rand() % height; // rastgele yem konumu
        nTail++; // yılanın uzunluğunu 1 arttır yem yedikçe !

    }





}

int main()

{

    system("color B");
    Setup();
    while(!gameOver)

    {

        Draw();
        Giris();
        Hareket();
        Sleep(10); // 10 saniye geçiş sürsün

    }

    return 0;

}
