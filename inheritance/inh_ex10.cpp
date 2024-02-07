//построим новую иерархию классов, которая решает проблемы,
//вытекающие из представленной выше критики традиционной иерархии

/*

 1) Система пользовательского интерфейса должна быть деталью реализации,
скрытой от пользователей, не желающих знать о ней.

 2) Класс Ival_box не должен содержать данных.

 3) Изменения в системе пользовательского интерфейса не должны требовать
перекомпиляции кода, использующего классы иерархии Ivalbox.

 4) Различные варианты Ivalbox для разных систем пользовательского
интерфейса должны иметь возможность сосуществовать в нашей программе.
 */

class BBwindow{
protected:
    int some_data;
    int another_data;
public:
    //..........
};

class Ival_box{
public:
    virtual int get_value() = 0;
    virtual void set_value(int i) = 0;
    virtual void reset_value(int i) = 0;
    virtual void prompt() = 0;
    virtual bool was_changed() const = 0;
    virtual ~Ival_box(){}
};

class Ival_slider:public Ival_box, protected BBwindow{
public:
    Ival_slider(int, int);
    ~Ival_slider();

    int get_value();
    void set_value(int i);
    //.......
protected:
    // функции, замещающие виртуальные функции,
    // например, В В window:: draw (), BBwindow:: mouse 1hit()
private:
    //данные для slider
};

class Ival_dial: public Ival_box, protected BBwindow{/*.....*/};
class Flashing_ival_slider: public Ival_slider{/*.....*/};
class Popup_ival_slider:public Ival_slider{/*.....*/};