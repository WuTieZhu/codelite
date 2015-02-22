//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2013 by Eran Ifrah
// file name            : cl_aui_notebook_art.h
//
// -------------------------------------------------------------------------
// A
//              _____           _      _     _ _
//             /  __ \         | |    | |   (_) |
//             | /  \/ ___   __| | ___| |    _| |_ ___
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/
//              \____/\___/ \__,_|\___\_____/_|\__\___|
//
//                                                  F i l e
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#ifndef CLAUIMAINNOTEBOOKTABART_H
#define CLAUIMAINNOTEBOOKTABART_H

#include <wx/aui/auibook.h>
#include <wx/pen.h>
#include "codelite_exports.h"
#include <wx/dcgraph.h>
#include <wx/colour.h>

#define TAB_CTRL_HEIGHT 30

class IManager;
class WXDLLIMPEXP_SDK clAuiMainNotebookTabArt : public wxAuiDefaultTabArt
{
protected:
    IManager* m_manager;
    // The tab area background colour
    wxColour m_bgColour;

    // The tab area pen colour (used to mark the tab area borders)
    wxColour m_penColour;
    wxColour m_activeTabPenColour;
    wxColour m_innerPenColour;

    // The text colour
    wxColour m_activeTabTextColour;
    wxColour m_tabTextColour;

    // A singe tab background colour
    wxColour m_activeTabBgColour;
    wxColour m_tabBgColour;
    
    double m_tabRadius;
    
    wxBitmap m_bmpClose;
    wxBitmap m_bmpCloseHover;
    wxBitmap m_bmpClosePressed;

protected:
    virtual void DoSetColours();
    virtual void DoInitializeColoursFromTheme();

public:
    clAuiMainNotebookTabArt(IManager* manager);
    virtual ~clAuiMainNotebookTabArt();

    virtual wxAuiTabArt* Clone() { return new clAuiMainNotebookTabArt(*this); }
    virtual void DrawBackground(wxDC& dc, wxWindow* wnd, const wxRect& rect);
    virtual void DrawTab(wxDC& dc,
                         wxWindow* wnd,
                         const wxAuiNotebookPage& page,
                         const wxRect& in_rect,
                         int close_button_state,
                         wxRect* out_tab_rect,
                         wxRect* out_button_rect,
                         int* x_extent);
    virtual wxSize GetTabSize(wxDC& dc,
                              wxWindow* wnd,
                              const wxString& caption,
                              const wxBitmap& bitmap,
                              bool active,
                              int closeButtonState,
                              int* xExtent);
                              
    int GetAdditionalBorderSpace(wxWindow* wnd) { return 0; }
};

#endif // CLAUIMAINNOTEBOOKTABART_H
