<?php
// $Id$

/**
 * @file
 * helper file for admin pages
 * @author Bèr Kessels  <ber@webschuur.com   >
 * @link http://webschuur.com
 * @package ideal_payment_credits
 */

function ideal_payment_credits_settings() {
  $form['ideal_payment_credits_path_error'] = array(
    '#type' => 'textfield',
    '#title' => t('Error path'),
    '#description' => t('Drupal path where to return on error'),
    '#default_value' => variable_get('ideal_payment_credits_path_error', ''),
  );

  $form['ideal_payment_credits_path_success'] = array(
    '#type' => 'textfield',
    '#title' => t('Success path'),
    '#description' => t('Drupal path where to return on success. Most often a "thank you" page.'),
    '#default_value' => variable_get('ideal_payment_credits_path_success', ''),
  );

  return system_settings_form($form);
}

function ideal_payment_credits_staffel() {
  for ($i = 1; $i <= 10; $i++) {
    $form['ideal_payment_credits_staffel_amount_'. $i] = array(
      '#type' => 'textfield',
      '#title' => t('A batch of'),
      '#default_value' => variable_get('ideal_payment_credits_staffel_amount_'. $i, ''),
      '#size' => 5,
      '#prefix' => '<div class="container-inline">',
    );
    $form['ideal_payment_credits_staffel_costs_'. $i] = array(
      '#type' => 'textfield',
      '#title' => t('credits will cost %curr', array('%curr' => variable_get('ideal_payment_api_currency', 'EUR'))),
      '#default_value' => variable_get('ideal_payment_credits_staffel_costs_'. $i, ''),
      '#size' => 7,
      '#suffix' => '</div>',
    );
  }

  return system_settings_form($form);
}