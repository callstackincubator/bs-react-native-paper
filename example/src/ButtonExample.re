open BsReactNative;
open Paper;
open Navigation;

module Styles = {
  open Style;

  let container = style([flex(1.0)]);

  let row =
    style([
      flexDirection(Row),
      flexWrap(Wrap),
      paddingHorizontal(Pt(12.)),
    ]);

  let button = style([margin(Pt(4.))]);
};

let component = ReasonReact.statelessComponent("Button Example");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  render: _self =>
    <StackNavigator.Screen headerTitle="Button" navigation>
      ...{
           () =>
             <ScrollView style=Styles.container>
               <List.Section title="Text button">
                 <View style=Styles.row>
                   <Button onPress={_event => ()}>
                     {ReasonReact.string("default")}
                   </Button>
                   <Button onPress={_event => ()} color="#5FCB11">
                     {ReasonReact.string("custom")}
                   </Button>
                   <Button disabled=true onPress={_event => ()}>
                     {ReasonReact.string("disabled")}
                   </Button>
                   <Button
                     icon={
                       Icon.Element(
                         Icon.renderIcon((props: Icon.iconProps) =>
                           <RNIcons.MaterialIcons
                             name=`_add
                             size={props.size}
                             color={props.color}
                           />
                         ),
                       )
                     }
                     onPress={_event => ()}>
                     {ReasonReact.string("icon")}
                   </Button>
                   <Button onPress={_event => ()} loading=true>
                     {ReasonReact.string("loading")}
                   </Button>
                 </View>
               </List.Section>
               <List.Section title="Outlined button">
                 <View style=Styles.row>
                   <Button
                     mode=`outlined onPress={_event => ()} style=Styles.button>
                     {ReasonReact.string("default")}
                   </Button>
                   <Button
                     style=Styles.button
                     mode=`outlined
                     onPress={_event => ()}
                     color="#5FCB11">
                     {ReasonReact.string("custom")}
                   </Button>
                   <Button
                     style=Styles.button
                     mode=`outlined
                     disabled=true
                     onPress={_event => ()}>
                     {ReasonReact.string("disabled")}
                   </Button>
                   <Button
                     icon={Icon.Name("add")}
                     style=Styles.button
                     mode=`outlined
                     onPress={_event => ()}>
                     {ReasonReact.string("icon")}
                   </Button>
                   <Button
                     style=Styles.button
                     mode=`outlined
                     onPress={_event => ()}
                     loading=true>
                     {ReasonReact.string("loading")}
                   </Button>
                 </View>
               </List.Section>
               <List.Section title="Contained button">
                 <View style=Styles.row>
                   <Button
                     mode=`contained
                     onPress={_event => ()}
                     style=Styles.button>
                     {ReasonReact.string("default")}
                   </Button>
                   <Button
                     style=Styles.button
                     mode=`contained
                     onPress={_event => ()}
                     color="#5FCB11">
                     {ReasonReact.string("custom")}
                   </Button>
                   <Button
                     style=Styles.button
                     mode=`contained
                     disabled=true
                     onPress={_event => ()}>
                     {ReasonReact.string("disabled")}
                   </Button>
                   <Button
                     icon={Icon.Name("add")}
                     style=Styles.button
                     mode=`contained
                     onPress={_event => ()}>
                     {ReasonReact.string("icon")}
                   </Button>
                   <Button
                     style=Styles.button
                     mode=`contained
                     onPress={_event => ()}
                     loading=true>
                     {ReasonReact.string("loading")}
                   </Button>
                 </View>
               </List.Section>
               <List.Section title="Custom icon">
                 <View style=Styles.row>
                   <Button
                     mode=`outlined
                     onPress={_event => ()}
                     icon={
                       Icon.Element(
                         Icon.renderIcon((props: Icon.iconProps) =>
                           <Image
                             source={
                               URI(
                                 Image.(
                                   imageURISource(
                                     ~uri=
                                       "https://avatars0.githubusercontent.com/u/17571969?v=3&s=400",
                                     (),
                                   )
                                 ),
                               )
                             }
                             style=Style.(
                               style([
                                 width(Pt(props.size)),
                                 height(Pt(props.size)),
                               ])
                             )
                           />
                         ),
                       )
                     }
                     style=Styles.button>
                     {ReasonReact.string("Custom component")}
                   </Button>
                 </View>
               </List.Section>
             </ScrollView>
         }
    </StackNavigator.Screen>,
};
