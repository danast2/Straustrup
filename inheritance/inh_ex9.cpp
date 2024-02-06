class Ival_box{
protected:
    int val;
    int low, high;
    bool changed;
public:
    Ival_box(int ll, int hh){changed = false; val = low = ll; high = hh;}
    virtual int get_value(){changed = false; return val;} // для приложения
    virtual void set_value(int i){changed = true; val = i;} // для пользователей
    virtual void  reset_value(int i){changed = false; val = i;} // для приложения

    virtual void promt(){};
    virtual bool was_changed()const {return changed;}
};

void interact(Ival_box* pb){
    pb->promt(); //оповестить пользователя
    //........
    if(pb->was_changed()){
        int i = pb->get_value();
        // новое значение,  делаем ....
    } else{
        //старое значение, значит  делаем ....
        //........
    }
}

class Ival_slider:public Ival_box{
    //графические атрибуты, определяющие вид ползунка и тд
public:
    //Ival_slider(int ll, int hh): Ival_box(ll, hh) {changed = false; val = low = ll; high = hh;};
    Ival_slider(int, int);
    int get_value();
    void prompt();
};


void some_fact(){
    Ival_box* p1 = new Ival_slider(0, 5);
    //interact(p1);

    Ival_box* p2 = new Ival_slider(1, 12);
    //interact(p2);
}