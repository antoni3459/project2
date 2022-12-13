#pragma once
#include "../BaseMenu.h"

class LabelControl;
class CalendarControl;

class BookingViewData:public BaseMenu
{
	DECLARE_CLASS_INFO(BaseMenu)

private:
	LabelControl* firstName = nullptr;
	LabelControl* lastName = nullptr;
	LabelControl* numberOfPeople = nullptr;
	CalendarControl* calendar = nullptr;

public:
	BookingViewData() = default;
	BookingViewData(Windows* _owner);
	BookingViewData(const BookingViewData& _copy) = default;

private:
	void Delete();
	void ReturnToBookingView();

public:
	void Initialize()override;
	void Open()override;

};

