/* File mstest2.c Sound Generator. */
#include <Mediastreamer2/msfilter.h>
#include <Mediastreamer2/msticker.h>
#include <Mediastreamer2/dtmfgen.h>
#include <Mediastreamer2/mssndcard.h>

int main()
{
    ms_init();
  
    /* Instantiating filters. */
    MSFilter  *voidsource = ms_filter_new(MS_VOID_SOURCE_ID);
    MSFilter  *dtmfgen = ms_filter_new(MS_DTMF_GEN_ID);
    MSSndCard *card_playback = ms_snd_card_manager_get_default_card(ms_snd_card_manager_get());
    MSFilter  *snd_card_write = ms_snd_card_create_writer(card_playback);
  
    /* Instantiating ticker. */
    MSTicker *ticker = ms_ticker_new();
    
    /* We connect filters in a chain. */
    ms_filter_link(voidsource, 0, dtmfgen, 0);
    ms_filter_link(dtmfgen, 0, snd_card_write, 0);
   
    /* We connect the clock source. */
    ms_ticker_attach(ticker, voidsource);
   
    /* We turn on the sound generator. */
    char key='1';
    ms_filter_call_method(dtmfgen, MS_DTMF_GEN_PLAY, (void*)&key);
    
    /* We give time for all data blocks to be received by the sound card.*/
    ms_sleep(2);   
}
