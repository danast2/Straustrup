//shape - форма
/*class Shape{
public:
    virtual void rotate(int){error("Shape::rotate");} //не элегантно
    virtual void draw(int){error("Shape::draw");}
};*/

//Создание таких «бесформенных» объектов хотя и допустимо, но лишено всякого
//смысла:

//Shape s; глупо: "shapeless shape"


//класс с одной или несколькими чисто виртуальными ф-циями является
//абстрактным классом (abstract class), объекты которого создавать недопустимо!

#include <list>
class Shape{ //абстрактный класс
public:
    virtual void rotate(int) = 0; //чисто виртуальная ф-ция (pure virtual),
    virtual void draw(int) = 0; // с помощью инициализатора =0
    virtual bool is_closed(int) = 0;

};

//error
//Shape s;

//абстрактный класс может использоваться
// только как интерфейсный и базовый для других классов

class Point{/*...*/};

class Circle: public Shape
{
public:
    void rotate(int);   //замещает Shape::rotate
    void draw(int); //замещает Shape::draw
    bool is_closed(int){return true;}   //замещает Shape::is_closed

    Circle(Point p, int r);
private:
    Point center;
    int radius;
};

/*
    Чисто виртуальная функция, не определенная и в производном классе, остается
чисто виртуальной, и поэтому такой производный класс также является
абстрактным. Это открывает нам возможности постепенного осуществления реализации
классовых иерархий:
 */

class Polygon:public Shape{ // абстрактный класс
public:
    bool is_closed(){return true;} //замещает Shape::is_closed
    //... draw и rotate не замещаются
};

//Polygon b; error, объект абстрактного классаа Polygon

class Irregular_polygon: public Polygon
{
    std::list<Point> lp;
public:
    void draw(); //замещает Shape::draw
    void rotate(int); //замещает Shape::rotate
    //.....
};

//Irregular_polygon poly(some_point)  - Всё нормально!
// (если есть подходящий конструктор)

/*Важным примером применения абстрактных классов является предоставление
        интерфейса без какой-либо реализации. Например, операционная система может
        скрывать детали реализации аппаратных драйверов за вот таким абстрактным
интерфейсом:*/
class Character_device{
public:
    virtual int open (int opt) =0;
    virtual int close (int opt) =0;
    virtual int read (char* p, int n) =0;
    virtual int write (const char* p, int n) =0;
    virtual int ioctl (int something) =0;
    virtual ~Character_device() {} // виртуальный деструктор
};