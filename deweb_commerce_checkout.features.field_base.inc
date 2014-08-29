<?php
/**
 * @file
 * deweb_commerce_checkout.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function deweb_commerce_checkout_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_delivery_price'
  $field_bases['field_delivery_price'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_delivery_price',
    'foreign keys' => array(),
    'indexes' => array(
      'currency_price' => array(
        0 => 'amount',
        1 => 'currency_code',
      ),
    ),
    'locked' => 0,
    'module' => 'commerce_price',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'commerce_price',
  );

  return $field_bases;
}
