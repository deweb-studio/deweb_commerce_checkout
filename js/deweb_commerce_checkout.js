(function ($) {
  Drupal.behaviors.deweb_commerce_checkout = {
    attach: function (context, settings) {
      // Your Javascript code goes here
      dForm = function()
      {
          var self = this;
      }
      dForm.prototype =
      {
        fields:$('.field-type-addressfield'),
        selfText:'Самовывоз',
        address:$('input[name=customer_profile_shipping\\[commerce_customer_address\\]\\[und\\]\\[0\\]\\[thoroughfare\\]]'),
        select:$('.form-item-customer-profile-shipping-addressbook select'),
        locality:$('input[name=customer_profile_shipping\\[commerce_customer_address\\]\\[und\\]\\[0\\]\\[locality\\]]'),
        localityText:"Киев",
        init:function(){
          var self = this;
          self.fields.css({'overflow':'hidden'});
          self.locality.css({'overflow':'hidden'});
          self.select.find('option').each(function(){
            if ($(this).html() == self.selfText) {
              $(this).hide();
            }          });
          if (self.select.find('option[selected=selected]').html() == self.selfText){
            $('.form-item-customer-profile-shipping-addressbook').hide();
          }
          self.select.on('change' , function(){
            var selectValue = $(this).find('option[value='+this.value+']').html();
            if (selectValue == self.selfText) {
              $('.delivery_checker[value=0]').click();  // 0 is term id selfDelivery mode
            }
          });
        },
        change:function(value){
          var self = this;
          if (!value) return;
          switch(value){
            case '2':  // 2 is term id for all Ukraine delivery mode
              self.locality.parents('.form-type-textfield').slideUp();
              self.locality.val(self.localityText);
            case '1':  // 1 is term id Only for Kiev delivery mode
              if (!self.fields.hasClass('expanded')){
                self.fields.slideDown().addClass('expanded');
                self.select.parents('.form-type-select').slideDown();
              }
              if (value == 1) {  // 1 is term id Only for Kiev delivery mode
                self.locality.parents('.form-type-textfield').slideDown();
                self.locality.val('');
              }
              if (self.address.val() == self.selfText){
                self.address.val('');
              }
              if (self.select.find('option[value='+self.select.val()+']').html() == self.selfText){
                self.select.val('none').change();
              }
              break;
            case '0': // 0 is term id selfDelivery mode
              if (self.select.size()){
                // Check delivery checker
                if (self.select.find('option[selected=selected]').html() != self.selfText && self.select.val() != 'none') {
                    // if present selfDelivery set she
                    var selfDeliveryPresent = false;
                    self.select.find('option').each(function(){
                      if ($(this).html() == self.selfText && !selfDeliveryPresent){
                        self.select.val($(this).attr('value')).change();
                        selfDeliveryPresent = true;
                     }
                    });
                   if (!selfDeliveryPresent) {
                    self.select.val('none').change();
                   }
                } else {
                  self.fields.slideUp().removeClass('expanded');
                  self.address.val(self.selfText);
                  self.locality.val(self.localityText);
                  self.select.parents('.form-type-select').slideUp();
                }
              } else {
                self.fields.slideUp().removeClass('expanded');
                self.address.val(self.selfText);
                self.locality.val(self.localityText);
              }
              break;
          }
          // body...
        }
      }

      if ($('.delivery_checker').size() && $('body').hasClass('page-checkout')){
        var value = $('.delivery_checker:checked').val();

        deliveryForm = new dForm();
        deliveryForm.init();

        $('.delivery_checker').on('change',function(){
          var newValue = $('.delivery_checker:checked').val();
          if (newValue == value) {
            return;
          }
          value = newValue;
          deliveryForm.change(newValue);
        });

        deliveryForm.change($('.delivery_checker:checked').val());

      }

    }
  };


}(jQuery));
