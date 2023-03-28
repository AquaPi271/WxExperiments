// #include <wx/wxprec.h>

// #ifndef WX_PRECOMP
#include <wx/wx.h>
// #endif

class wxImagePanel : public wxPanel {
public:
  wxImagePanel(wxFrame *parent, wxString file, wxBitmapType format);

  void paintEvent(wxPaintEvent &event);
  void paintNow();
  void OnSize(wxSizeEvent &event);
  void render(wxDC &dc);

  DECLARE_EVENT_TABLE();

private:
  wxImage image;
  wxBitmap resized;
  int w = 0;
  int h = 0;
};

BEGIN_EVENT_TABLE(wxImagePanel, wxPanel)
// catch paint events
EVT_PAINT(wxImagePanel::paintEvent)
// size event
EVT_SIZE(wxImagePanel::OnSize)
END_EVENT_TABLE()

wxImagePanel::wxImagePanel(wxFrame *parent, wxString file, wxBitmapType format)
    : wxPanel(parent) {
  // Load the file... ideally add a check to see if loading was successful.
  // TODO:  Will change this to create an image of current ray trace.
  // bool loaded = image.LoadFile(file, format);
  // if (!loaded) {
  //  std::cerr << "Could not load file:" << file << std::endl;
  //  exit(1);
  //}
  // image.LoadFile(file, format);
  image.Create(800, 600);

  for (auto sh = 0; sh < 600; ++sh) {
    for (auto sw = 0; sw < 800; ++sw) {
      image.SetRGB(sw, sh, static_cast<unsigned char>(0x255), 0x0, 0x0);
    }
  }

  w = -1;
  h = -1;
}

// Callback event for when the panel needs to be redrawn.
// Also can be directly invoked via Refresh() / Update().
void wxImagePanel::paintEvent(wxPaintEvent &event) {
  // Possibly need double buffered DCs.
  // TODO:  Try graphics context instead?
  wxPaintDC dc(this);
  render(dc);
}

// Alternatively, you can use a clientDC to paint on the panel
// at any time. Using this generally does not free you from
// catching paint events, since it is possible that e.g. the window
// manager throws away your drawing when the window comes to the
// background, and expects you will redraw it when the window comes
// back (by sending a paint event).
void wxImagePanel::paintNow() {
  // Possibly need double buffered DCs.
  // TODO:  Try graphics context instead?
  wxClientDC dc(this);
  render(dc);
}

// Render via the DC passed in.  Render is separated from how the DC
// was created (wxPaintDC or wxClientDC from paintEvent() or paintNow())
void wxImagePanel::render(wxDC &dc) {
  int neww = 0, newh = 0;
  dc.GetSize(&neww, &newh);

  if (neww != w || newh != h) {
    resized = wxBitmap(image.Scale(neww, newh /*, wxIMAGE_QUALITY_HIGH*/));
    w = neww;
    h = newh;
  }
  dc.DrawBitmap(resized, 0, 0, false);
}

// Here we call refresh to tell the panel to draw itself again.
// So when the user resizes the image panel the image should be resized too.
void wxImagePanel::OnSize(wxSizeEvent &event) {
  Refresh();
  // skip the event.
  event.Skip();
}

class BasicRayTraceApp : public wxApp {
public:
  virtual bool OnInit();

private:
  wxFrame *frame = nullptr;
  wxImagePanel *drawPane = nullptr;
};

wxIMPLEMENT_APP(BasicRayTraceApp);

bool BasicRayTraceApp::OnInit() {

  // Loads all image handlers built in this version of wxWidgets.
  // It is overkill if only using a subset of these images.  To limit to
  // precisely the needed images, Peek into the function for AddHandler.
  wxInitAllImageHandlers();

  wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);
  frame = new wxFrame(NULL, wxID_ANY, wxT("Hello wxDC"), wxPoint(50, 50),
                      wxSize(800, 600));

  drawPane = new wxImagePanel(frame, wxT("lake_erie.bmp"), wxBITMAP_TYPE_BMP);
  sizer->Add(drawPane, 1, wxEXPAND);

  frame->SetSizer(sizer);

  frame->Show(true);
  return true;
}
