#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "RightTriangle.h"
#include "AcuteTriangle.h"
#include "SlotMachine.h"

using namespace std;

/*
A method that draws a textual image of the shape object
polymorphically through Shape&

@param the shape to draw,
the foreground character to be used; the background character to be used
*/
void poly_draw_shape_by_ref(const Shape& shape, char fChar = '*', char bChar = ' ')
{
    Grid shape_box = shape.draw(fChar, bChar);
    cout << shape_box << endl;
}

int main()
{
    SlotMachine slot_machine; //create a slot machine object
    slot_machine.run(); // run the slot machine until the player decides to stop or runs out of tokens

    //  
    //    /******************************************************************************************************/
    //    /*FULL TESTS OF TASK ONE - UNCOMMENT LINES 32-140*/
    /*
        //1 - Examples on pages 5-8 of the Assignment
        cout << "1. Test the output using the insertion operator and name of the object (pp. 5-8).\n" << endl;
    
        cout << "Rectangle:\n " << endl;
        Rectangle rect{ 5, 7 };
        cout << rect << endl;
    
        cout << "Rhombus:\n " << endl;
        Rhombus ace{ 16, "Ace", "Ace of diamond" };
        cout << ace << endl;
      
        cout << "Acute Triangle:\n " << endl;
        AcuteTriangle at{ 17 };
        cout << at << endl;
    
        cout << "Acute Triangle - equivalently:\n " << endl;
        Shape *atptr = &at;
        cout << *atptr << endl;
        
        cout << "Acute Triangle - equivalently:\n " << endl;
        Shape &atref = at;
        cout << atref << endl;
        
        cout << "Right Triangle:\n " << endl;
        RightTriangle rt{ 10, "Carpenter's square" };
        cout << rt << endl;
    
        //2 - Same examples on pages 5-8 of the Assignment, but using toString() method this time
        cout << "2. Test the output using toString() method (pp. 5-8)\n" << endl;
    
        cout << "Rectangle:\n " << endl;
        cout << rect.toString() << endl;
    
        cout << "Rhombus: \n" << endl;
        cout << ace.toString() << endl;
    
        cout << "Acute Triangle: \n" << endl;
        cout << at.toString() << endl;
    
        cout << "Right Triangle: \n" << endl;
        cout << rt.toString() << endl;
    
        //3 Testing "draw" function using examples on pp. 9-11 of the Assignment
        cout << "3. Call the \"draw\" function statically (pp. 9-11)\n" << endl;
    
        cout << "Rhombus: " << endl;
        Grid aceBox = ace.draw('+', '.');
        cout << aceBox << endl;
    
        cout << "Rectangle:\n " << endl;
        Grid rectBox = rect.draw();
        cout << rectBox << endl;
        
        cout << "Acute Triangle: " << endl;
        Grid atBox = at.draw('^');
        cout << atBox << endl;
    
        cout << "Right Triangle: " << endl;
        Grid rtBox = rt.draw('-');
        cout << rtBox << endl;
    
        cout << "Right Triangle with different foreground and background characters: " << endl;
        Grid rtBox2 = rt.draw('\\', 'o');
        cout << rtBox2 << endl;
    
        cout << "Rhombus with different foreground and background characters: " << endl;
        Grid aceBox1 = ace.draw('o');
        cout << aceBox1 << endl;
    
        //4 Testing "draw" function through Shape& (p. 12 of the Assignment)
        cout << "4. Call the \"draw\" function polymorphically through Shape& (p. 12)\n" << endl;
    
        cout << "Rectangle:\n " << endl;
        poly_draw_shape_by_ref(rect);
    
        cout << "Rhombus: " << endl;
        poly_draw_shape_by_ref(ace, '+', '.');
    
        cout << "Acute Triangle: " << endl;
        poly_draw_shape_by_ref(at, '^');
    
        cout << "Right Triangle: " << endl;
        poly_draw_shape_by_ref(rt, '-');
    
        //5 Testing "draw" function through std::unique_ptr (p. 13 of the Assignment)
        cout << "5. Call the \"draw\" function polymorphically through std::unique_ptr\n" << endl;
    
        cout << "Rectangle:\n " << endl;
        std::unique_ptr<Shape> rectShape{ new Rectangle {5,7} };
        Grid rectBox1 = rectShape->draw();
        cout << rectBox1 << endl;
    
        cout << "Rhombus: " << endl;
        std::unique_ptr<Shape> aceShape{ new Rhombus { 16, "Ace", "Ace of diamond" } };
        Grid aceBox2 = aceShape->draw('^');
        std::cout << aceBox2 << endl;
    
        cout << "Acute Triangle: " << endl;
        std::unique_ptr<Shape> atShape{ new AcuteTriangle { 17 } };
        Grid atBox1 = atShape->draw('^');
        std::cout << atBox1 << endl;
    
        cout << "Right Triangle: " << endl;
        std::unique_ptr<Shape> rtShape { new RightTriangle { 10, "Carpenter's square" } };
        Grid rtBox1 = rtShape->draw('-');
        std::cout << rtBox1 << endl;
    }
     */
    ///*********************************************************************************************/
    return 0;
}
