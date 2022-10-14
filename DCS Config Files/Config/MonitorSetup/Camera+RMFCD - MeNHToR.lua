_  = function(p) return p; end;
name = _('Camera + RMFCD MeNHToR');
Description = 'Right MFCD on the right and camera on the center'
Viewports =
{
     Center =
     {
          x = 0;
          y = 0;
          width  = 2560;
          height = 1440;
          viewDx = 0;
          viewDy = 0;
          aspect = screen.aspect / 1.7;
     }
}

F18_IFEI =
{
     x = 2600;
     y = 460;
     width = 420;
     height = 175;
}

LEFT_MFCD =
{
     x = 2560;
     y = 0;
     width = 410;
     height = 410;
}

RIGHT_MFCD =
{
     x = 4080;
     y = 0;
     width = 410;
     height = 410;
}

CENTER_MFCD =
{
     x = 3280;
     y = 680;
     width = 410;
     height = 410;
}



UIMainView = Viewports.Center
GU_MAIN_VIEWPORT = Viewports.Center