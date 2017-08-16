# Connect() function with signals and slots

This example come from *developper.com* (https://qt.developpez.com/doc/4.7/signalsandslots/).

With qt we can make a counter class like this:

    #include <QObject>
    class Counter : public QObject
    {
         Q_OBJECT
    public:
         Counter() { m_value = 0; }
         int value() const { return m_value; }
    public slots:
         void setValue(int value);
    signals:
         void valueChanged(int newValeur);
    private:
         int m_value;};

In qt we have two special class parameter that are **signals** and **slot**. The signals are function that act as trigger to launch the slots functions. Consider the following setValue function:

    void Counter::setValue(int value)
    {
        if (value != m_value) {
            m_value = value;
            emit valueChanged(value);
        }
    }

This function emit the signal *valueChanged* when the parameter value of the class changes (the example is a little paradoxal because the signal is emit in the slot function...).

The signals and slots are linked together with the connect() function:

    Counter a, b;
    QObject::connect(&a, SIGNAL(valueChanged(int)), &b, SLOT(setValue(int)));

when the signal is emitted by a, b do the slot function. Moreover if the signal and slot function have the same number and type of arguments they can be transmitted one to the other *via* the connect function like on the previous example. When the value of a change, the signal contain the value and so the slot function change the value of b with the new value of b.

Untill qt 5 a new syntaxe can be used:

    QObject::connect(a, &a::valueChanged, b, &b::setValue);