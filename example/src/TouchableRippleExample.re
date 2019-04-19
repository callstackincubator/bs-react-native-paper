open BsReactNative;
open BsReactNativePaper;
open Paper;
open Navigation;

module Styles = {
  open Style;

  let container = style([flex(1.0), backgroundColor(String("#ffffff"))]);
  let ripple =
    style([flex(1.), alignItems(Center), justifyContent(Center)]);
};

let component = ReasonReact.statelessComponent("TouchableRipple Example");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  render: _self =>
    <StackNavigator.Screen headerTitle="TouchableRipple example" navigation>
      ...{
           () =>
             <View style=Styles.container>
               <TouchableRipple
                 style=Styles.ripple
                 onPress={_event => ()}
                 rippleColor="rgba(0, 0, 0, .32)">
                 <View pointerEvents=`none>
                   <Paragraph>
                     {ReasonReact.string("Press anywhere")}
                   </Paragraph>
                 </View>
               </TouchableRipple>
             </View>
         }
    </StackNavigator.Screen>,
};
