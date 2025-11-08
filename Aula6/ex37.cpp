#include <iostream>
#include <vector>
using namespace std;

struct Client{
    string name;
    int arrival;
    int products;
    int departure;
    int start;
    int checkout;
    bool here = false;
};

struct Checkout{
    vector<Client> fila;
    int speed;
    int ncustomers = 0;
};

void clientLeft(vector<Checkout>& checkouts, vector<Client>& clients, Client& client){
    for (Client& c : clients){
        if (c.name == client.name) {break;}
        if (c.here && c.departure<client.arrival){
            if (!checkouts[c.checkout].fila.empty() && checkouts[c.checkout].fila.front().name==c.name){
                checkouts[c.checkout].fila.erase(checkouts[c.checkout].fila.begin());
                c.here = false;
            }
        }
    }
}

void chooseCheckout(vector<Checkout>& checkouts, vector<Client>& clients, Client& client){
    clientLeft(checkouts, clients, client);
    int res=0;
    for (int i=1;i<checkouts.size();i++){
        int sz_res=checkouts[res].fila.size();
        int sz_i=checkouts[i].fila.size();
        int last_res=checkouts[res].fila.empty() ? 0 : checkouts[res].fila.back().products;
        int last_i=checkouts[i].fila.empty() ? 0 : checkouts[i].fila.back().products;
        if(sz_i<sz_res){res=i;}
        else if(sz_i==sz_res){
            if(last_i<last_res) {res=i;}
            else if(last_i==last_res && i<res) {res=i;}
        }
    }
    int start_time = client.arrival;
    if (!checkouts[res].fila.empty()){
        Client& last=checkouts[res].fila.back();
        if (last.departure>start_time){start_time=last.departure;}
    }
    client.start=start_time;
    client.departure=start_time+10+checkouts[res].speed*client.products;
    client.checkout=res;
    client.here=true;

    checkouts[res].fila.push_back(client);
    checkouts[res].ncustomers++;
}

int main(){
    int ncheckouts;
    cin >> ncheckouts;
    vector<Checkout> checkouts(ncheckouts);
    for (int i=0;i<ncheckouts;i++){
        int s;
        cin >> s;
        checkouts[i].speed=s;
    }
    int nclients;
    cin >> nclients;
    vector<Client> clients(nclients);
    for (int i=0;i<nclients;i++){
        string name;
        int arrival, p;
        cin>>name>>arrival>>p;
        clients[i].name=name;
        clients[i].arrival=arrival;
        clients[i].products=p;
    }
    for (Client& client:clients){
        chooseCheckout(checkouts, clients, client);
    }
    for (int i=0;i<ncheckouts;i++){
        cout<<"Checkout #"<<i+1<<": "<<checkouts[i].ncustomers<<endl;
        for (Client& client:clients){
            if(client.checkout==i){
                cout<<". "<<client.name<<' '<<client.arrival<<' '<<client.start<<' '<<client.departure<<endl;
            }
        }
    }
}

