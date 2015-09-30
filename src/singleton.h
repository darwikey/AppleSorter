#pragma once


template <typename T>
class Singleton
{
protected:

    // Constructeur/destructeur
    Singleton () { }
    ~Singleton () { }

public:
    // Interface publique
    static T *getInstance()
    {
        if (nullptr == _singleton)
        {

            _singleton = new T;
        }

        return (static_cast<T*> (_singleton));
    }

	static bool isInit()
	{
		return _singleton!=nullptr;
	}

    static void Destroy ()
    {
        if (nullptr != _singleton)
        {
            delete _singleton;
            _singleton = nullptr;
        }
    }

private:

    // Unique instance
    static T *_singleton;

};

template <typename T>
T *Singleton<T>::_singleton = nullptr;


