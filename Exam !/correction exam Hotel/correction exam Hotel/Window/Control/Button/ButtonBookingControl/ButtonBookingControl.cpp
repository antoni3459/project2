#include "ButtonBookingControl.h"
#include "../../../../Booking/Booking.h"

ButtonBookingControl::ButtonBookingControl(int _controlID, HWND _owner, const Rect& _rect, const wchar_t* _text, Booking* _bookings)
    :super(_controlID, _owner, _rect, _text)
{
    bookings = _bookings;
}

ButtonBookingControl::ButtonBookingControl(const ButtonBookingControl& _copy)
{
    bookings = _copy.bookings;
}

HWND ButtonBookingControl::Create()
{
    return HWND();
}

void ButtonBookingControl::OnUse()
{
    OnClickBooking.Invoke(bookings);
    super::OnClick;
}
