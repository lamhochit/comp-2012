#include "gold_card.h"

#include "silver_card.h"

//TODO: Implement the constructor here.
GoldCard::GoldCard(int id, string na, int coup, int tick): SilverCard(id, na, coup), number_of_free_tickets(2) {}

//TODO: Print "Dear regular member {name},
//            remaining benefits are {get_credits} credits,
//                                   {get_number_of_cupons} coupons,
//                                   {number_of_free_tickets} free tickets. ".
void GoldCard::check_member_benefits() const {
    cout << "Dear Gold member " << get_name() <<",\n"
    << "remaining benefits are " << get_credits() << " credits,\n"
    << "                       " << get_number_of_coupons() << " coupons, \n"
    << "                       " << number_of_free_tickets
    << " free tickets. \n";
}

//TODO: Exchange credits for tick free tickets (20 credits for 1 coupon).
void GoldCard::exchange_credits_for_free_tickets(int tick) {
	if (tick <= 0) {
		cout << "SORRY, the input must be positive." << endl;
	}
	else if (tick*20 > get_credits())
    {
        cout << "SORRY, not enough credits for " << tick << " tickets.\n"
        << "You have " << get_credits() << " credits left and can only exchange for " << floor(get_credits()/20)
        << "tickets.";
	}
	else
    {
	    set_credits(get_credits()-tick*20);
	    number_of_free_tickets += tick;
    }
}
