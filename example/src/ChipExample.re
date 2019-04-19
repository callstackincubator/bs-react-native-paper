open BsReactNative;
open BsReactNativePaper;
open Paper;
open Navigation;

module Styles = {
  open Style;

  let container = style([flex(1.0), backgroundColor(String("#ffffff"))]);
  let row =
    style([
      paddingHorizontal(Pt(12.)),
      flexDirection(Row),
      flexWrap(Wrap),
    ]);
  let chip = style([margin(Pt(4.))]);
};

let component = ReasonReact.statelessComponent("Chip Example");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  render: _self =>
    <StackNavigator.Screen headerTitle="Chip example" navigation>
      ...{
           () =>
             <ScrollView style=Styles.container>
               <List.Section title="Flat chip">
                 <View style=Styles.row>
                   <Chip onPress={_event => ()} style=Styles.chip>
                     {ReasonReact.string("Simple")}
                   </Chip>
                   <Chip
                     onPress={_event => ()}
                     onClose={_event => ()}
                     style=Styles.chip>
                     {ReasonReact.string("Close Button")}
                   </Chip>
                   <Chip
                     icon={
                       Icon.Element(
                         Icon.renderIcon((props: Icon.iconProps) =>
                           <RNIcons.MaterialIcons
                             name=`_favorite
                             color={props.color}
                             size={props.size}
                           />
                         ),
                       )
                     }
                     onPress={_event => ()}
                     onClose={_event => ()}
                     style=Styles.chip>
                     {ReasonReact.string("Icon")}
                   </Chip>
                   <Chip
                     avatar={
                       <Image
                         source={
                           Required(Packager.require("../assets/avatar.jpg"))
                         }
                       />
                     }
                     onPress={_event => ()}
                     onClose={_event => ()}
                     style=Styles.chip>
                     {ReasonReact.string("Avatar")}
                   </Chip>
                   <Chip
                     selected=true
                     avatar={
                       <Image
                         source={
                           Required(Packager.require("../assets/avatar.jpg"))
                         }
                       />
                     }
                     onPress={_event => ()}
                     style=Styles.chip>
                     {ReasonReact.string("Avatar (selected)")}
                   </Chip>
                   <Chip
                     disabled=true
                     icon={Icon.Name("favorite")}
                     onClose={_event => ()}
                     style=Styles.chip>
                     {ReasonReact.string("Icon (disabled)")}
                   </Chip>
                   <Chip
                     disabled=true
                     avatar={
                       <Image
                         source={
                           Required(Packager.require("../assets/avatar.jpg"))
                         }
                       />
                     }
                     style=Styles.chip>
                     {ReasonReact.string("Avatar (disabled)")}
                   </Chip>
                 </View>
               </List.Section>
               <List.Section title="Outlined chip">
                 <View style=Styles.row>
                   <Chip
                     mode=`outlined onPress={_event => ()} style=Styles.chip>
                     {ReasonReact.string("Simple")}
                   </Chip>
                   <Chip
                     mode=`outlined
                     onPress={_event => ()}
                     onClose={_event => ()}
                     style=Styles.chip>
                     {ReasonReact.string("Close Button")}
                   </Chip>
                   <Chip
                     mode=`outlined
                     icon={
                       Icon.Element(
                         Icon.renderIcon((props: Icon.iconProps) =>
                           <RNIcons.MaterialIcons
                             name=`_favorite
                             color={props.color}
                             size={props.size}
                           />
                         ),
                       )
                     }
                     onPress={_event => ()}
                     onClose={_event => ()}
                     style=Styles.chip>
                     {ReasonReact.string("Icon")}
                   </Chip>
                   <Chip
                     mode=`outlined
                     avatar={
                       <Image
                         source={
                           Required(Packager.require("../assets/avatar.jpg"))
                         }
                       />
                     }
                     onPress={_event => ()}
                     onClose={_event => ()}
                     style=Styles.chip>
                     {ReasonReact.string("Avatar")}
                   </Chip>
                   <Chip
                     mode=`outlined
                     selected=true
                     avatar={
                       <Image
                         source={
                           Required(Packager.require("../assets/avatar.jpg"))
                         }
                       />
                     }
                     onPress={_event => ()}
                     style=Styles.chip>
                     {ReasonReact.string("Avatar (selected)")}
                   </Chip>
                   <Chip
                     mode=`outlined
                     disabled=true
                     icon={Icon.Name("favorite")}
                     onClose={_event => ()}
                     style=Styles.chip>
                     {ReasonReact.string("Icon (disabled)")}
                   </Chip>
                   <Chip
                     mode=`outlined
                     disabled=true
                     avatar={
                       <Image
                         source={
                           Required(Packager.require("../assets/avatar.jpg"))
                         }
                       />
                     }
                     style=Styles.chip>
                     {ReasonReact.string("Avatar (disabled)")}
                   </Chip>
                 </View>
               </List.Section>
             </ScrollView>
         }
    </StackNavigator.Screen>,
};
