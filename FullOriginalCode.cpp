namespace stdlib
{
    typedef unsigned long long size_t;

    size_t G_StringSize(const char* S_StringToBeParsed)
    {
        size_t M_Size = 0;

        while (S_StringToBeParsed[M_Size] != '\0')
        {
            M_Size++;
        }

        return M_Size;
    }

    class String
    {
    private:
        char*  M_Variable;
        size_t M_VariableContentSize;
    public:
        String(const char* S_ValueToBeWrited);

        ~String();

        size_t G_Size();
        char* G_String();

        void M_Clear();
        void M_PushBack(const char* S_StringToBePushed);
        void M_Cut(size_t _StartPosition, size_t _FinishPosition);
        // char* M_CutWithReturn(size_t _StartPosition, size_t _FinishPosition);

        bool C_Empty();

        char& operator[](const int S_InVariableContentMemberIndex) const;
    };

    String::String(const char* S_ValueToBeWrited)
    {
        size_t S_ValueSize = G_StringSize(S_ValueToBeWrited);

        this->M_VariableContentSize = S_ValueSize;
        this->M_Variable = new char[S_ValueSize + 1];

        for (size_t _MicroIterator = 0; _MicroIterator < S_ValueSize; _MicroIterator++)
        {
            this->M_Variable[_MicroIterator] = S_ValueToBeWrited[_MicroIterator];
        }

        this->M_Variable[this->M_VariableContentSize] = '\0';
    }

    String::~String()
    {
        delete[] this->M_Variable;
    }

    char& String::operator[](const int S_InVariableContentMemberIndex) const
    {
        if (S_InVariableContentMemberIndex < 0)
        {
            return this->M_Variable[0];
        }

        return this->M_Variable[S_InVariableContentMemberIndex];
    }

    size_t String::G_Size()
    {
        return this->M_VariableContentSize;
    }

    char* String::G_String()
    {
        return this->M_Variable;
    }

    void String::M_Clear()
    {
        delete[] this->M_Variable;
        this->M_VariableContentSize = 0;
    }

    void String::M_PushBack(const char* S_StringToBePushed)
    {
        const size_t S_OldVariableContentSize = this->G_Size();
        char* S_OldVariableContent = new char[S_OldVariableContentSize + 1];

        for (size_t _MicroIterator = 0; _MicroIterator < S_OldVariableContentSize; _MicroIterator++)
        {
            S_OldVariableContent[_MicroIterator] = this->M_Variable[_MicroIterator];
        }

        S_OldVariableContent[S_OldVariableContentSize] = '\0';

        const size_t S_PushedStringSize = G_StringSize(S_StringToBePushed);
        const size_t S_NewSize = S_OldVariableContentSize + S_PushedStringSize;

        delete[] this->M_Variable;

        this->M_VariableContentSize = S_NewSize;
        this->M_Variable = new char[S_NewSize + 1];

        /* Push old content */
        for (size_t _MicroIterator = 0; _MicroIterator < S_OldVariableContentSize; _MicroIterator++)
        {
            this->M_Variable[_MicroIterator] = S_OldVariableContent[_MicroIterator];
        }

        /* Push new content */
        size_t _SubMicroIterator = 0;

        for (size_t _MicroIterator = S_OldVariableContentSize; _MicroIterator < S_NewSize; _MicroIterator++)
        {
            this->M_Variable[_MicroIterator] = S_StringToBePushed[_SubMicroIterator];
            _SubMicroIterator++;
        }

        this->M_Variable[this->M_VariableContentSize] = '\0';

        delete[] S_OldVariableContent;
    }

    void String::M_Cut(size_t _StartPosition, size_t _FinishPosition)
    {
        const size_t S_OldVariableContentSize = this->G_Size();
        char* S_OldVariableContent = new char[S_OldVariableContentSize + 1];

        for (size_t _MicroIterator = 0; _MicroIterator < S_OldVariableContentSize; _MicroIterator++)
        {
            S_OldVariableContent[_MicroIterator] = this->M_Variable[_MicroIterator];
        }

        S_OldVariableContent[S_OldVariableContentSize] = '\0';

        delete[] this->M_Variable;

        size_t S_NewSize = this->G_Size() - (_StartPosition - _FinishPosition);

        this->M_VariableContentSize = S_NewSize;
        this->M_Variable = new char[S_NewSize + 1];

        if (_StartPosition == 0)
        {
            size_t M_SubMicroIterator = 0;
            for (size_t _MicroIterator = _FinishPosition; _MicroIterator < S_NewSize; _MicroIterator++)
            {
                this->M_Variable[M_SubMicroIterator] = S_OldVariableContent[_MicroIterator];
                M_SubMicroIterator++;
            }

            this->M_Variable[this->M_VariableContentSize] = '\0';

            delete[] S_OldVariableContent;
        }
        else if (_StartPosition > 0)
        {
            size_t M_SubMicroIterator = 0;

            for (size_t _MicroIterator = 0; _MicroIterator < _StartPosition; _MicroIterator++)
            {
                this->M_Variable[M_SubMicroIterator] = S_OldVariableContent[_MicroIterator];
                M_SubMicroIterator++;
            }

            for (size_t _MicroIterator = _FinishPosition; _MicroIterator < S_NewSize; _MicroIterator++)
            {
                this->M_Variable[M_SubMicroIterator] = S_OldVariableContent[_MicroIterator];
                M_SubMicroIterator++;
            }

            this->M_Variable[this->M_VariableContentSize] = '\0';

            delete[] S_OldVariableContent;
        }
    }

    bool String::C_Empty()
    {
        return this->M_VariableContentSize == 0;
    }
}
