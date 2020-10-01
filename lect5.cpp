class TheCollection { // На динамическом массиве
  public:  
    TheCollection();
    TheCollection(const TheCollection&);
    TheCollection(const TheCollection&&);
    ~TheCollection();
    void add(const TheData &obj);
    void del(int pos);
    void del(const TheData &obj);
    TheData &get(int pos);
    void set(int pos, const TheData&);
  private:
    TheData *objects;// Массив объектов
    int count; // Число объектов.
};
