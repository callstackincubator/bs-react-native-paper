open BsReactNative;
open Paper;
open Navigation;

module Styles = {
  open Style;

  let container =
    style([flex(1.0), justifyContent(Center), alignItems(Center)]);

  let common = [
    margin(Pt(8.)),
    height(Pt(80.)),
    width(Pt(80.)),
    alignItems(Center),
    justifyContent(Center),
  ];

  let surface1 = style([elevation(1.), ...common]);
  let surface2 = style([elevation(2.), ...common]);
  let surface4 = style([elevation(4.), ...common]);
  let surface6 = style([elevation(6.), ...common]);
  let surface9 = style([elevation(9.), ...common]);
  let surface12 = style([elevation(12.), ...common]);
};

let component = ReasonReact.statelessComponent("SurfaceExample");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  render: self =>
    <StackNavigator.Screen headerTitle="Surface example" navigation>
      ...{
           () =>
             <View style=Styles.container>
               <Surface style=Styles.surface1>
                 <Text> {ReasonReact.string("1")} </Text>
               </Surface>
               <Surface style=Styles.surface2>
                 <Text> {ReasonReact.string("2")} </Text>
               </Surface>
               <Surface style=Styles.surface4>
                 <Text> {ReasonReact.string("4")} </Text>
               </Surface>
               <Surface style=Styles.surface6>
                 <Text> {ReasonReact.string("6")} </Text>
               </Surface>
               <Surface style=Styles.surface9>
                 <Text> {ReasonReact.string("9")} </Text>
               </Surface>
               <Surface style=Styles.surface12>
                 <Text> {ReasonReact.string("12")} </Text>
               </Surface>
             </View>
         }
    </StackNavigator.Screen>,
};
