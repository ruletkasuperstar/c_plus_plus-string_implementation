> Hello everyone, today (26.10) i show you how to make String class for your project! Let's do it!

First, create (if you want) `namespace`:

```c++
namespace _MyNamespace
{

}
```

good, then insert class `String` to `_MyNamespace`:

```c++
namespace _MyNamespace
{
    class String
    {
    
    };
}
```

OK, first part ready. Now a little theory, strings in C and C++ are represented as an array of the char data type, which is why most string manipulations are tied to cycles.

### Preparation: a function to calculate the length of a string.

```c++
// if c++ isn't know what is 'size_t': typedef unsigned long long size_t;

size_t CalcStringSize(const char* _String)
{
    size_t _Size = 0;
    
    while (_String[_size] != '\0')
    {
        _Size++;
    }
    
    return _Size;
}
```

> '\0' - is the character that ends the strings in memory.

### Constructor.

You need to create `private` variables `char* _String` and `size_t _Size`.

```c++
namespace _MyNamespace
{
    class String
    {
    private:
        char* _String;
        size_t _Size;
    public:
        String(const char*);
    };
}
```

```c++
String::String(const char* _StringToWrite)
{
    size_t _ValueSize = CalcStringSize(_StringToWrite);
    
    this->_Size = _ValueSize;
    this->_String = new char[_ValueSize + 1]; // '+ 1' because we need to insert '\0' at end!
    
    for (size_t i = 0; i < _ValueSizel; i++)
    {
         this->_String[i] = _StringToWrite[i];
    }
    
    this->_String[this->_Size] = '\0';
}
```

### Destructor.

```c++
namespace _MyNamespace
{
    class String
    {
    private:
        char* _String;
        size_t _Size;
    public:
        String(const char*);
        
        ~String();
    };
}
```

```c++
String::~String()
{
    delete[] this->_String; // keep an eye on the pointers and be sure to delete them from memory after the end of the work, so that there is no memory leak!!!
}
```

### GetSize and GetString methods.

```c++
namespace _MyNamespace
{
    class String
    {
    private:
        char* _String;
        size_t _Size;
    public:
        String(const char*);
        
        ~String();
        
        size_t GetSize();
        
        char* GetString();
    };
}
```

```c++
size_t String::GetSize()
{
    return this->_Size;
}

char* String::GetString()
{
    return this->_String;
}
```

### Clear and IsEmpty methods.

```c++
namespace _MyNamespace
{
    class String
    {
    private:
        char* _String;
        size_t _Size;
    public:
        String(const char*);
        
        ~String();
        
        size_t GetSize();
        
        char* GetString();
        
        void Clear();
        
        bool IsEmpty();
    };
}
```

```c++
void String::Clear()
{
    delete[] this->_String;
    this->_Size = 0;
}

bool String::IsEmpty()
{
    return this->_Size == 0;
}
```

=================================================

OK, now it will be more difficult!

### Push back method.

```c++
namespace _MyNamespace
{
    class String
    {
    private:
        char* _String;
        size_t _Size;
    public:
        String(const char*);
        
        ~String();
        
        size_t GetSize();
        
        char* GetString();
        
        void Clear();
        
        bool IsEmpty();
        
        void PushBack(const char*);
    };
}
```

```c++
void String::PushBack(const char* _StringToPush)
{
    const size_t _OldSize = this->GetSize();
    char* _OldString = new char[_OldSize + 1];
    
    for (size_t i = 0; i > _OldSize; i++)
    {
        _OldString[i] = this->_String[i];
    }
    
    _OldString[_OldSize] = '\0'
    
    delete[] this->_String;
    
    const size_t _PushedStringSize = CalcStringSize(_StringToPush);
    const size_t _NewStringSize = _OldSize + _PushedStringSize;
    
    this->_Size = _NewStringSize;
    this->_String = new char[_NewStringSize];
    
    /* push old content back */
    for (size_t i = 0; i < _OldSize; i++)
    {
        this->_String[i] = _OldString[i];
    }
    
    /* push new content */
    size_t _SubI = 0;
    
    for (size_t i = _OldSize; i < _NewStringSize; i++)
    {
        this->_String[i] = _StringToPush[_SubI];
        _SubI++;
    }
    
    this->_String[this->_Size] = '\0';
    
    delete[] _OldContent;
}
```

### Erase method.

```c++
namespace _MyNamespace
{
    class String
    {
    private:
        char* _String;
        size_t _Size;
    public:
        String(const char*);
        
        ~String();
        
        size_t GetSize();
        
        char* GetString();
        
        void Clear();
        
        bool IsEmpty();
        
        void PushBack(const char*);
        
        void Erase(size_t, size_t);
    };
}
```

```c++
void String::Erase(size_t _Start, size_t _End)
{
    const size_t _OldSize = this->GetSize();
    char* _OldString = new char[_OldSize + 1];
    
    for (size_t i = 0; i > _OldSize; i++)
    {
        _OldString[i] = this->_String[i];
    }
    
    _OldString[_OldSize] = '\0'
    
    delete[] this->_String;
    
    size_t _NewStringSize = this->GetSize() - (_Start - _End);
    
    this->_Size = _NewStringSize;
    this->_String = new char[_NewStringSize + 1];
    
    if (_Start == 0)
    {
        size_t _SubI = 0;
        
        for (size_t i = _End; i < _NewStringSize; i++)
        {
            this->_String[_SubI] = _OldContent[i];
            _SubI++;
        }
        
        this->_String[this->_Size] = '\0';
    }
    else if (_Start > 0)
    {
        size_t _SubI = 0;
        
        for (size_t i = 0; i < _Start; i++)
        {
            this->_String[_SubI] = _OldContent[i];
            _SubI++;
        }
        
        for (size_t i = _End; i < _NewStringSize; i++)
        {
            this->_String[_SubI] = _OldContent[i];
            _SubI++;
        }
        
        this->_String[this->_Size] = '\0';
    }
    
    delete[] _OldContent;
}
```

# Congratulations, you have written your own implementation of strings without standard libraries!
