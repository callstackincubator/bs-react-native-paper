open BsReactNative;
open BsReactNativePaper;
open Paper;
open Navigation;

module Styles = {
  open Style;

  let container = style([flex(1.0)]);

  let image = style([width(Pt(40.)), height(Pt(40.)), margin(Pt(8.))]);
};

let component = ReasonReact.statelessComponent("ListSection Example");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  render: _self =>
    <StackNavigator.Screen headerTitle="ListSection" navigation>
      ...{
           () =>
             <ScrollView style=Styles.container>
               <List.Section title="Single line">
                 <List.Item
                   left={
                     List.renderIcon((props: List.iconProps) =>
                       <List.Icon
                         icon={
                           Icon.Element(
                             Icon.renderIcon((iconProps: Icon.iconProps) =>
                               <RNIcons.MaterialIcons
                                 name=`_event
                                 color={iconProps.color}
                                 size={iconProps.size}
                               />
                             ),
                           )
                         }
                         color={props.color}
                       />
                     )
                   }
                   title="List item 1"
                 />
                 <List.Item
                   onPress={_event => ()}
                   left={
                     List.renderIcon((props: List.iconProps) =>
                       <List.Icon
                         icon={Icon.Name("redeem")}
                         color={props.color}
                       />
                     )
                   }
                   title="List item 2"
                 />
               </List.Section>
               <Divider />
               <List.Section title="Two line">
                 <List.Item
                   left={
                     List.renderIcon((_props: List.iconProps) =>
                       <Image
                         source={
                           Required(
                             Packager.require("../assets/email-icon.png"),
                           )
                         }
                         style=Styles.image
                       />
                     )
                   }
                   title="List item 1"
                   description="Describes item 1"
                 />
                 <List.Item
                   onPress={_event => ()}
                   left={
                     List.renderIcon((_props: List.iconProps) =>
                       <Image
                         source={
                           Required(
                             Packager.require("../assets/email-icon.png"),
                           )
                         }
                         style=Styles.image
                       />
                     )
                   }
                   right={
                     List.renderIcon((props: List.iconProps) =>
                       <List.Icon
                         icon={Icon.Name("info")}
                         color={props.color}
                       />
                     )
                   }
                   title="List item 2"
                   description="Describes item 2"
                 />
               </List.Section>
               <Divider />
               <List.Section title="Three line">
                 <List.Item
                   left={
                     List.renderIcon((_props: List.iconProps) =>
                       <Image
                         source={
                           Required(
                             Packager.require("../assets/email-icon.png"),
                           )
                         }
                         style=Styles.image
                       />
                     )
                   }
                   title="List item 1"
                   description="Describes item 1. Example of a very very long description."
                 />
                 <List.Item
                   onPress={_event => ()}
                   left={
                     List.renderIcon((_props: List.iconProps) =>
                       <Image
                         source={
                           Required(
                             Packager.require("../assets/email-icon.png"),
                           )
                         }
                         style=Styles.image
                       />
                     )
                   }
                   right={
                     List.renderIcon((props: List.iconProps) =>
                       <List.Icon
                         icon={
                           Icon.Element(
                             Icon.renderIcon((iconProps: Icon.iconProps) =>
                               <RNIcons.MaterialIcons
                                 name=`_starBorder
                                 color={iconProps.color}
                                 size={iconProps.size}
                               />
                             ),
                           )
                         }
                         color={props.color}
                       />
                     )
                   }
                   title="List item 2"
                   description="Describes item 2. Example of a very very long description."
                 />
               </List.Section>
             </ScrollView>
         }
    </StackNavigator.Screen>,
};
