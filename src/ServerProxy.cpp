#include "ServerProxy.hpp"
#include "EventMarshallingStrategy.hpp"
#include "GamestateMarshallingStrategy.hpp"

ServerProxy::ServerProxy( MarshallingStrategy<Event>*& evt, MarshallingStrategy<Gamestate>*& gs ) {
    this->setup( evt, gs ) ;
}

ServerProxy::ServerProxy() {
    MarshallingStrategy<Event>* m1 = new EventMarshlingStrategy() ;
    MarshallingStrategy<Gamestate>* m2 = new GamestateMarshallingStrategy() ;
    this->setup( m1, m2 ) ;
}

void ServerProxy::setup(MarshallingStrategy<Event>*& evt, MarshallingStrategy<Gamestate>*& gs) {
    this->m_event_marshalling_strategy = evt ;
    this->m_gamestate_marshalling_strategy = gs ;
}
