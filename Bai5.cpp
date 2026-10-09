#include <stdio.h>
#include <string.h>

#define MAX_TICKETS 5

struct Ticket {
    int ticket_id;
    char event_name[50];
    double price;
    int is_vip;
};

double calculate_ticket_price(double price, int is_vip);
int search_ticket(const struct Ticket list[], int total_tickets, int ticket_id);
void display_tickets(const struct Ticket list[], int total_tickets);
int add_ticket(struct Ticket list[], int total_tickets, struct Ticket new_ticket);
int delete_ticket(struct Ticket list[], int total_tickets, int ticket_id);

int main() {
    struct Ticket list[MAX_TICKETS];
    int total_tickets = 0;

    list[0].ticket_id = 101;
    strcpy(list[0].event_name, "Concert Music");
    list[0].price = 300000.0;
    list[0].is_vip = 0;

    list[1].ticket_id = 102;
    strcpy(list[1].event_name, "Tech Conference");
    list[1].price = 500000.0;
    list[1].is_vip = 1;

    total_tickets = 2;

    printf("=== DANH SACH VE BAN DAU ===\n");
    display_tickets(list, total_tickets);

    double vip_price = calculate_ticket_price(500000.0, 1);
    printf("Gia ve VIP sau phu thu: %.2f\n\n", vip_price);

    struct Ticket t3 = {103, "Art Exhibition", 200000.0, 0};
    total_tickets = add_ticket(list, total_tickets, t3);

    struct Ticket t4 = {104, "Sport Match", 400000.0, 1};
    total_tickets = add_ticket(list, total_tickets, t4);

    struct Ticket t5 = {105, "Comedy Show", 250000.0, 0};
    total_tickets = add_ticket(list, total_tickets, t5);

    struct Ticket t6 = {106, "Food Festival", 150000.0, 0};
    total_tickets = add_ticket(list, total_tickets, t6);

    printf("\n=== DANH SACH SAU KHI THEM ===\n");
    display_tickets(list, total_tickets);

    total_tickets = delete_ticket(list, total_tickets, 999);

    total_tickets = delete_ticket(list, total_tickets, 102);

    printf("\n=== DANH SACH SAU KHI XOA ===\n");
    display_tickets(list, total_tickets);

    return 0;
}

double calculate_ticket_price(double price, int is_vip) {
    if (is_vip == 1) {
        return price * 1.2;
    }
    return price;
}

int search_ticket(const struct Ticket list[], int total_tickets, int ticket_id) {
    int i;
    for (i = 0; i < total_tickets; i++) {
        if (list[i].ticket_id == ticket_id) {
            return i;
        }
    }
    return -1;
}

void display_tickets(const struct Ticket list[], int total_tickets) {
    int i;
    if (total_tickets == 0) {
        printf("Danh sach ve trong!\n");
        return;
    }
    printf("%-10s | %-20s | %-12s | %-10s\n", "ID", "Event Name", "Price", "Type");
    printf("---------------------------------------------------------------\n");
    for (i = 0; i < total_tickets; i++) {
        printf("%-10d | %-20s | %-12.2f | %-10s\n", 
            list[i].ticket_id, 
            list[i].event_name, 
            list[i].price, 
            list[i].is_vip == 1 ? "VIP" : "Standard");
    }
    printf("Tong so ve hien tai: %d\n\n", total_tickets);
}

int add_ticket(struct Ticket list[], int total_tickets, struct Ticket new_ticket) {
    if (total_tickets >= MAX_TICKETS) {
        printf("Canh bao: Danh sach ve da day!\n");
        return total_tickets;
    }
    list[total_tickets] = new_ticket;
    printf("Them thanh cong ve ma %d\n", new_ticket.ticket_id);
    return total_tickets + 1;
}

int delete_ticket(struct Ticket list[], int total_tickets, int ticket_id) {
    int index, i;
    if (total_tickets == 0) {
        printf("Canh bao: Danh sach ve rong!\n");
        return total_tickets;
    }
    index = search_ticket(list, total_tickets, ticket_id);
    if (index == -1) {
        printf("Canh bao: Khong tim thay ma ve %d!\n", ticket_id);
        return total_tickets;
    }
    for (i = index; i < total_tickets - 1; i++) {
        list[i] = list[i + 1];
    }
    printf("Xoa thanh cong ve ma %d\n", ticket_id);
    return total_tickets - 1;
}
