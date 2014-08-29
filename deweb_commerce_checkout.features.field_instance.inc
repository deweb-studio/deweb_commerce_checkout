<?php
/**
 * @file
 * deweb_commerce_checkout.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function deweb_commerce_checkout_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-delivery-field_delivery_price'
  $field_instances['taxonomy_term-delivery-field_delivery_price'] = array(
    'bundle' => 'delivery',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'product_category' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'fences_wrapper' => 'div',
    'field_name' => 'field_delivery_price',
    'label' => 'Стоимость доставки',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'commerce_price',
      'settings' => array(
        'currency_code' => 'default',
      ),
      'type' => 'commerce_price_full',
      'weight' => 41,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Стоимость доставки');

  return $field_instances;
}
