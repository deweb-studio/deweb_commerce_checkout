<?php
/**
 * @file
 * deweb_commerce_checkout.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function deweb_commerce_checkout_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
