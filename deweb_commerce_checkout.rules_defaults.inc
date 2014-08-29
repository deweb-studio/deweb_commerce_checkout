<?php
/**
 * @file
 * deweb_commerce_checkout.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function deweb_commerce_checkout_default_rules_configuration() {
  $items = array();
  $items['rules_delivery_fee'] = entity_import('rules_config', '{ "rules_delivery_fee" : {
      "LABEL" : "Delivery fee",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "php", "commerce_fees" ],
      "ON" : { "commerce_fees_order" : [] },
      "IF" : [
        { "AND" : [
            { "entity_has_field" : { "entity" : [ "commerce-order" ], "field" : "field_delivery" } },
            { "php_eval" : { "code" : "$term = taxonomy_term_load($commerce_order-\\u003Efield_delivery[LANGUAGE_NONE][0][\\u0027tid\\u0027]);\\r\\nif ($term-\\u003Efield_delivery_price) return TRUE;" } }
          ]
        }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : {
              "type" : "taxonomy_term",
              "id" : [ "commerce-order:field-delivery:tid" ]
            },
            "PROVIDE" : { "entity_fetched" : { "delivery_term" : "Delivery term" } }
          }
        },
        { "commerce_fees_apply" : {
            "entity" : [ "commerce-order" ],
            "fee" : "delivery",
            "amount" : {
              "select" : "delivery-term:tid",
              "php" : { "code" : "$term = taxonomy_term_load( $value);\\r\\nreturn $term-\\u003Efield_delivery_price[LANGUAGE_NONE][0][\\u0027amount\\u0027];" }
            },
            "currency_code" : "UAH",
            "include_tax" : "0"
          }
        }
      ]
    }
  }');
  return $items;
}
