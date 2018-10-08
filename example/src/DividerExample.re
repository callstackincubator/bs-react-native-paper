open BsReactNative;
open Paper;
open Navigation;

module Styles = {
  open Style;

  let container = style([flex(1.0)]);
  let item = style([marginVertical(Pt(10.)), marginLeft(Pt(10.))]);
};

let component = ReasonReact.statelessComponent("DividerExample");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  render: self =>
    <StackNavigator.Screen headerTitle="Divider example" navigation>
      ...{
           () =>
             <View style=Styles.container>
               <Title style=Styles.item>
                 {ReasonReact.string("Apple")}
               </Title>
               <Divider />
               <Title style=Styles.item>
                 {ReasonReact.string("Orange")}
               </Title>
               <Divider />
               <Title style=Styles.item>
                 {ReasonReact.string("Grapefruit")}
               </Title>
               <Divider />
               <Title style=Styles.item>
                 {ReasonReact.string("Lemon")}
               </Title>
               <Divider />
             </View>
         }
    </StackNavigator.Screen>,
};
