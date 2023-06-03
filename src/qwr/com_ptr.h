#pragma once

namespace qwr
{

// simplified version of _com_ptr_t
template <typename T>
class ComPtr
{
public:
    explicit ComPtr( ComPtr* p )
        : pInterface_( p )
    {
        if ( !p )
        {
            throw qwr::QwrException( "Internal error: com nullptr" );
        }
        else
        {
            AddRef();
        }
    }

    ComPtr() = default;
    ComPtr( decltype( nullptr ) ) noexcept
    {
    }

    ComPtr( const ComPtr& cp ) noexcept
        : pInterface_( cp.pInterface_ )
    {
        _AddRef();
    }

    ComPtr( ComPtr&& cp ) noexcept
        : pInterface_( cp.pInterface_ )
    {
        cp.pInterface_ = nullptr;
    }

    ComPtr( T* pInterface ) noexcept
        : pInterface_( pInterface )
    {
        _AddRef();
    }

    // Copies the pointer. If fAddRef is true, the interface will be AddRef()ed.
    ComPtr( T* pInterface, bool fAddRef ) noexcept
        : pInterface_( pInterface )
    {
        if ( fAddRef )
        {
            _AddRef();
        }
    }

    ComPtr& operator=( const ComPtr& p ) noexcept
    {
        if ( pInterface_ != p.pInterface_ )
        {
            ComPtr copied{ p };
            swap( *this, copied );
        }

        return *this;
    }

    ComPtr& operator=( ComPtr&& cp ) noexcept
    {
        if ( pInterface_ != cp.pInterface_ )
        {
            T* pOldInterface = pInterface_;

            pInterface_ = cp.pInterface_;
            cp.pInterface_ = nullptr;

            if ( pOldInterface )
            {
                pOldInterface->Release();
            }
        }

        return *this;
    }

    ComPtr& operator=( ::std::nullptr_t ) noexcept
    {
        _Release();
        pInterface_ = nullptr;
        return *this;
    }

    friend void swap( ComPtr& left, ComPtr& right ) noexcept
    {
        T* tmp = left.pInterface_;
        left.pInterface_ = right.pInterface_;
        right.pInterface_ = tmp;
    }

    ~ComPtr() noexcept
    {
        _Release();
    }

    // Saves/sets the interface without AddRef()ing. This call
    // will release any previously acquired interface.
    //
    void Attach( T* pInterface ) noexcept
    {
        _Release();
        pInterface_ = pInterface;
    }

    // Saves/sets the interface only AddRef()ing if fAddRef is true.
    // This call will release any previously acquired interface.
    //
    void Attach( T* pInterface, bool fAddRef )
    {
        _Release();
        pInterface_ = pInterface;

        if ( fAddRef )
        {
            if ( pInterface )
            {
                pInterface->AddRef();
            }
            else
            {
                throw qwr::QwrException( "Internal error: com nullptr" );
            }
        }
    }

    // Set the interface pointer to nullptr, so that it isn't Release()'ed.
    //
    T* Detach() noexcept
    {
        T* const old = pInterface_;
        pInterface_ = nullptr;
        return old;
    }

    operator T*() const noexcept
    {
        return pInterface_;
    }

    operator T&() const
    {
        if ( pInterface_ )
        {
            return *pInterface_;
        }

        throw qwr::QwrException( "Internal error: com nullptr" );
    }

    // Allows an instance of this class to act as though it were the actual interface.
    T& operator*() const
    {
        if ( pInterface_ )
        {
            return *pInterface_;
        }

        throw qwr::QwrException( "Internal error: com nullptr" );
    }

    // Returns the address of the interface pointer contained in this class. This is useful when using the COM/OLE
    // interfaces to create this interface.
    T** operator&() noexcept
    {
        _Release();
        pInterface_ = nullptr;
        return &pInterface_;
    }

    // Allows this class to be used as the interface itself.
    T* operator->() const
    {
        if ( pInterface_ )
        {
            return pInterface_;
        }

        throw qwr::QwrException( "Internal error: com nullptr" );
    }

    operator bool() const noexcept
    {
        return pInterface_ != nullptr;
    }

    bool operator==( decltype( nullptr ) ) const noexcept
    {
        return pInterface_ == nullptr;
    }

    friend bool operator==( decltype( nullptr ), const ComPtr& _This ) noexcept
    {
        return _This.pInterface_ == nullptr;
    }

    bool operator!=( decltype( nullptr ) ) const noexcept
    {
        return pInterface_ != nullptr;
    }

    friend bool operator!=( decltype( nullptr ), const ComPtr& _This ) noexcept
    {
        return _This.pInterface_ != nullptr;
    }

    void Release()
    {
        if ( pInterface_ )
        {
            pInterface_->Release();
            pInterface_ = nullptr;
        }
        else
        {
            throw qwr::QwrException( "Internal error: com nullptr" );
        }
    }

    void AddRef()
    {
        if ( pInterface_ )
        {
            pInterface_->AddRef();
        }
        else
        {
            throw qwr::QwrException( "Internal error: com nullptr" );
        }
    }

    T* GetInterfacePtr() const noexcept
    {
        return pInterface_;
    }

    T*& GetInterfacePtr() noexcept
    {
        return pInterface_;
    }

private:
    T* pInterface_ = nullptr;

    void _Release() noexcept
    {
        if ( pInterface_ )
        {
            pInterface_->Release();
        }
    }

    void _AddRef() noexcept
    {
        if ( pInterface_ )
        {
            pInterface_->AddRef();
        }
    }
};

} // namespace qwr
