<?php
/**
 * Implements base_settings_form()
 */
function deweb_commerce_checkout_pane_settings_form($checkout_pane) {
  $form['deweb_commerce_checkout_pane_delivery_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Delivery radio buttons title'),
    '#default_value' => variable_get('deweb_commerce_checkout_pane_delivery_title', ''),
  );
  return $form;
}

/**
 * Implements base_checkout_form()
 */
function deweb_commerce_checkout_pane_checkout_form($form, $form_state, &$checkout_pane, $order) {
	$checkout_pane['title'] = '';

  $checkout_form['deweb_commerce_checkout_pane_delivery'] = array(
    '#type' => 'radios',
    '#title' => variable_get('deweb_commerce_checkout_pane_delivery_title', t('Delivery')),
    '#reqired' => true,
    '#attributes' => array(
    	'class' => array('delivery_checker')),
  );

  $options = array();
  $voc = taxonomy_vocabulary_machine_name_load('delivery');
  $delivery = taxonomy_get_tree($voc->vid,0,null,true);
  $default_delivery_tid = false;
  $description = array();
  foreach($delivery as $term){
  	$name = $term->name;
  	if (!$default_delivery_tid) $default_delivery_tid = $term->tid;
  	if ($term->field_delivery_price) {
  		$price = $term->field_delivery_price[LANGUAGE_NONE][0];
  		$name .= ' ('.commerce_currency_format($price['amount'],$price['currency_code']).')';
  	}
 	$options[$term->tid] = $name;
  	if ($term->description) $checkout_form['deweb_commerce_checkout_pane_delivery'][$term->tid] = array( '#description' => strip_tags(check_markup($term->description, 'plain_text'),'<br>'));
  }
  if (!isset($order->field_delivery[LANGUAGE_NONE][0]['tid'])){
  	$order->field_delivery[LANGUAGE_NONE][0]['tid'] = $default_delivery_tid;
  } else $default_delivery_tid = $order->field_delivery[LANGUAGE_NONE][0]['tid'];


  $checkout_form['deweb_commerce_checkout_pane_delivery']['#options'] = $options;
  $checkout_form['deweb_commerce_checkout_pane_delivery']['#default_value'] = $default_delivery_tid;
;


  return $checkout_form;
}


/**
 * Implements base_checkout_form_submit()
 */
function deweb_commerce_checkout_pane_checkout_form_submit($form, &$form_state, $checkout_pane, $order) {
    $order->field_delivery[LANGUAGE_NONE][0]['tid'] = $form_state['values']['deweb']['deweb_commerce_checkout_pane_delivery'];
}
