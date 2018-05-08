//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

#include "FontEnumerator.h"

using namespace uwpfontlist;

using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
    listData = ref new Vector<String^>();
    listView->ItemsSource = listData;
    
    LoadFonts();
}

void uwpfontlist::MainPage::LoadFonts()
{
    auto fontEnumerator = ref new FontEnumeration::FontEnumerator();
    Platform::Array<Platform::String^>^ sysFonts = fontEnumerator->ListSystemFonts();

    std::sort(begin(sysFonts), end(sysFonts), [](String^ a, String^ b) {
        return 0 > String::CompareOrdinal(a, b);
    });

    listData->ReplaceAll(sysFonts);
}
