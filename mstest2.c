/* File mstest2.c Sound Generator. */
#include <mediastreamer2/msfilter.h>
#include <mediastreamer2/msticker.h>
#include <mediastreamer2/dtmfgen.h>
#include <mediastreamer2/mssndcard.h>

int main()
{
    
    MSFactory *mf;  /* Factory of Mediastremer's filters. */
    mf = ms_factory_new();
	ms_factory_init_voip(mf);
  
    /* Instantiating filters. */
    MSFilter *voidsource = ms_factory_create_filter(mf, MS_VOID_SOURCE_ID);
    MSFilter *dtmfgen = ms_factory_create_filter(mf, MS_DTMF_GEN_ID);
    MSSndCardManager *scm; /* Soundcards manager. */
    scm = ms_factory_get_snd_card_manager(mf);
    MSSndCard *card_playback = ms_snd_card_manager_get_default_card(scm);
    MSFilter  *snd_card_write = ms_snd_card_create_writer(card_playback);
/*
    MSFilter  *voidsource = ms_filter_new(MS_VOID_SOURCE_ID);
    MSFilter  *dtmfgen = ms_filter_new(MS_DTMF_GEN_ID);
    MSSndCard *card_playback = ms_snd_card_manager_get_default_card(ms_snd_card_manager_get());
    MSFilter  *snd_card_write = ms_snd_card_create_writer(card_playback);
  */

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
