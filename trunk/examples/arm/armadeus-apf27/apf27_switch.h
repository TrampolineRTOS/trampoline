/**
 * Trivial driver to configure APF27 (-Dev) to
 * raise an interrupt when the switch S1 (APF27-Dev) is pressed
 *
 * @author Jonathan ILIAS-PILLET, ESEO
 * @date 2/11/2010
 */
#if !defined __APF27_SWITCH_H
#define __APF27_SWITCH_H

/**
 * initialize board to make S1 able to raise interrupts
 */
void apf27_s1_init ();

/**
 * aknoledge an interrupt from S1
 */
void apf27_s1_ack_int ();

#endif /* __APF27_SWITCH_H */
