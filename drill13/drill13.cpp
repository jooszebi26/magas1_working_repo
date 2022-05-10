/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    int xmax = 800;
    int ymax = 1000;
    int x_grid = 100;
    int y_grid = 100;

    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

    Lines grid;
    for (int x = x_grid; x < xmax; x+=x_grid)
        grid.add(Point(x,0),Point(x,800));
    for (int y = y_grid; y < ymax; y+=y_grid)
        grid.add(Point(0,y),Point(800,y));

    Vector_ref<Rectangle> diagonal;

    for (int i = 0; i<8; i++)
    {
        diagonal.push_back(new Rectangle{Point{i*100,i*100},100,100});
        diagonal[i].set_fill_color(Color::red);
        win.attach(diagonal[i]);
    }

    Image img1 (Point{400,0},"image1.jpg");
    Image img2 (Point{400,200},"image1.jpg");
    Image img3 (Point{600,200},"image1.jpg");
    Image img4 (Point{0,0},"image2.jpg");
        
    win.attach(grid);
    win.attach(img1);
    win.attach(img2);
    win.attach(img3);
    win.attach(img4);
    
    int img4_x = 100;
    int img4_y = 0;
    int counter = 0;
    int big_counter = 0;
    while(win.wait_for_button())
    {
        img4.move(img4_x,img4_y);
        counter += 1;
        big_counter +=1;
        if (counter == 8)
        {
            img4_x = -800;
            img4_y = 100; 
            img4.move(logo_x,logo_y);
            img4_x = 100;
            img4_y = 0;
            counter = 0;
        }
        if (big_counter == 64)
        {
            return 0;
        }
    }
    win.wait_for_button();

 
}