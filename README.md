# manusoft-rstring
Windows resource string class based on CString

This old class was motivated by the desire to simpify the following common
code pattern for initializing a CString from embedded string resources:

  CString sRes;
  sRes.LoadString(IDS_RES);
  pCtrl->SetWindowText(sRes);

By adding suitable constructors, RString can perform the LoadString inline:

  pCtrl->SetWindowText(RString(IDS_RES));

In addition to the extra constructors, RString adds Format and FormatMessage
method variants that take a string resource ID.

To use RString, just include the header in your MFC based project:

#include "RString.h"

Note: this class was written in 2002, and is based on CString from that time
period. No effort has been made to modernize it.
