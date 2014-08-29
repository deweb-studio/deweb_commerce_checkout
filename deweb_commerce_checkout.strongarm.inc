<?php
/**
 * @file
 * deweb_commerce_checkout.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function deweb_commerce_checkout_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'deweb_commerce_checkout_pane_delivery_title';
  $strongarm->value = 'Доставка';
  $export['deweb_commerce_checkout_pane_delivery_title'] = $strongarm;

  return $export;
}
