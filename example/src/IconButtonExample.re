open BsReactNative;
open Paper;
open Navigation;

module Styles = {
  open Style;

  let container =
    style([
      flex(1.0),
      flexDirection(Row),
      padding(Pt(8.)),
      backgroundColor(String("#ffffff")),
    ]);
};

let component = ReasonReact.statelessComponent("TypographyExample");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  render: _self =>
    <StackNavigator.Screen headerTitle="Typography example" navigation>
      ...{
           () =>
             <View style=Styles.container>
               <IconButton
                 icon={Icon.Name("add-a-photo")}
                 size=24.
                 onPress={() => ()}
               />
               <IconButton
                 icon={
                   Icon.Element(
                     Icon.renderIcon((props: Icon.iconProps) =>
                       <RNIcons.MaterialIcons
                         name=`_https
                         size={props.size}
                         color={props.color}
                       />
                     ),
                   )
                 }
                 size=24.
                 color="#4CAF50"
                 onPress={() => ()}
               />
             </View>
         }
    </StackNavigator.Screen>,
};
